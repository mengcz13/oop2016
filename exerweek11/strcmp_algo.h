#ifndef STRCMP_ALGO_H
#define STRCMP_ALGO_H
class Pattern {
public:
	char* pattern;
	int len;
protected:
	Pattern(const char* pstr);
	~Pattern();
	virtual void compile() = 0;
};

class KmpPattern : public Pattern {
public:
	int* next;
	KmpPattern(const char* str);
	~KmpPattern();
protected:
	void compile();
};

class KrPattern : public Pattern {
public:
	unsigned long long hash;
	unsigned long long* powertable;
	KrPattern(const char* str);
	~KrPattern();
	unsigned long long hashfunc(const char* str, int len) const;
	unsigned long long quick_hash(unsigned long long src, int len, char pop, char push) const;
protected:
	void compile();
};

// strcmp functions, return the position of the head of the first substring matching the pattern string
const char* strcmp_kmp(const char* str, int lenstr, const KmpPattern* pat);
const char* strcmp_kr(const char* str, int lenstr, const KrPattern* pat);

#endif