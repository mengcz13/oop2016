#include "strcmp_algo.h"
#include <cstring>
#include <cstdio>
#define CONSTA 31

Pattern::Pattern(const char* pstr) {
	len = strlen(pstr);
	pattern = new char[len];
	memcpy(pattern, pstr, sizeof(char) * len);
}

Pattern::~Pattern() {
	if (pattern != NULL)
		delete []pattern;
}

KmpPattern::KmpPattern(const char* str) : next(NULL), Pattern(str) {
	next = new int[len];
	memset(next, 0, sizeof(int) * len);
	compile();
}

KmpPattern::~KmpPattern() {
	if (next != NULL)
		delete []next;
}

void KmpPattern::compile() {
	next[0] = -1;
	int p = 0, t = next[p];
	while (p < len - 1) {
		if (t == -1 || pattern[t] == pattern[p]) {
			next[++p] = ++t;
		}
		else {
			t = next[t];
		}
	}
}

KrPattern::KrPattern(const char* str) : hash(0), powertable(NULL), Pattern(str) {
	powertable = new unsigned long long[len];
	powertable[0] = 1;
	for (int i = 1; i < len; ++i) {
		powertable[i] = powertable[i - 1] * CONSTA;
	}
	compile();
}

KrPattern::~KrPattern() {
	if (powertable != NULL)
		delete []powertable;
}

unsigned long long KrPattern::hashfunc(const char* str, int len) const { // BKDR HASH FUNCTION
	unsigned long long hash = 0;
	for (int i = 0; i < len; ++i) {
		hash = hash * CONSTA + str[i];
	}
	return hash;
}

unsigned long long KrPattern::quick_hash(unsigned long long src, int len, char pop, char push) const {
	return (src - (unsigned long long)pop * powertable[len - 1]) * (unsigned long long)CONSTA + (unsigned long long)push;
}

void KrPattern::compile() {
	hash = hashfunc(pattern, len);
}

const char* strcmp_kmp(const char* str, int lenstr, const KmpPattern* pat) {
	int p = 0, t = 0;
	while (p < lenstr) {
		if (t == -1 || str[p] == pat->pattern[t]) {
			++p;
			++t;
		}
		else {
			t = pat->next[t];
		}
		if (t == pat->len)
			return (&str[p - t]);
	}
	return NULL;
}

const char* strcmp_kr(const char* str, int lenstr, const KrPattern* pat) {
	unsigned long long src = pat->hashfunc(str, pat->len);
	for (int i = 0; i <= lenstr - pat->len; ++i) {
		if (src == pat->hash) {
			bool same = true;
			for (int j = 0; j < pat->len; ++j)
				if (str[i + j] != pat->pattern[j]) {
					same = false;
					break;
				}
			if (same)
				return (&str[i]);
		}
		if (i < lenstr - pat->len) {
			src = pat->quick_hash(src, pat->len, str[i], str[i + pat->len]);
		}
		else
			return NULL;
	}
	return NULL;
}