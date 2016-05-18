#include "strcmp_algo.h"
#include <cstring>
#include <cstdio>

const char space[4] = {' ', '\t', '\n', '\r'};

bool isspace(char c) {
	for (int i = 0; i < 4; ++i)
		if (space[i] == c)
			return true;
	return false;
}

int space_filter(char* src, char* dst, int len) {
	int tail = 0;
	for (int i = 0; i < len; ++i) {
		if (!isspace(src[i]))
			dst[tail++] = src[i];
	}
	dst[tail] = '\0';
	return tail;
}

int main(int argc, char** argv) {
	if (argc < 4) {
		printf("Usage: ./main <patternfile> <srcfile> <resultfile>\n");
		return -1;
	}
	FILE* pf = fopen(argv[1], "r");
	int patternnum = 0, maxlen = 0;
	fscanf(pf, "%d%d", &patternnum, &maxlen);
	char* pattern = new char[patternnum * maxlen];
	memset(pattern, 0, sizeof(char) * patternnum * maxlen);
	int r = 0;
	while (!feof(pf)) {
		fscanf(pf, "%s", &pattern[(r++)*maxlen]);
	}
	fclose(pf);
	FILE* outf = fopen(argv[argc - 1], "w");
	const int buffersize = (1 << 20);
	char* buffer = new char[buffersize];
	char* filtered = new char[buffersize];
	memset(buffer, 0, sizeof(char) * buffersize);
	memset(filtered, 0, sizeof(char) * buffersize);
	for (int i = 0; i < argc - 3; ++i) {
		FILE* fsrc = fopen(argv[2 + i], "r");
		fprintf(outf, "Source file: %s\n", argv[2 + i]);
		int len = fread(buffer, sizeof(char), buffersize, fsrc);
		int flen = space_filter(buffer, filtered, len);
		for (int j = 0; j < patternnum; ++j) {
			KmpPattern kmpp(&pattern[j*maxlen]);
			KrPattern krpp(&pattern[j*maxlen]);
			int kmpnum = 0, krnum = 0;
			const char* p = strcmp_kmp(filtered, flen, &kmpp);
			while (p) {
				++kmpnum;
				p = strcmp_kmp(p + 1, flen - (p - filtered + 1), &kmpp);
			}
			p = strcmp_kr(filtered, flen, &krpp);
			while (p) {
				++krnum;
				p = strcmp_kr(p + 1, flen - (p - filtered + 1), &krpp);
			}
			fprintf(outf, "%s:\nKMP: %d    KR: %d\n", &pattern[j*maxlen], kmpnum, krnum);
		}
		fclose(fsrc);
		memset(buffer, 0, sizeof(char) * buffersize);
		memset(filtered, 0, sizeof(char) * buffersize);
	}
	fclose(outf);
	delete []pattern;
	delete []buffer;
	delete []filtered;
	return 0;
}