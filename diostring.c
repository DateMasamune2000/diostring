#include "diostring.h"

int str_copyraw(string *str, const char *raw)
{
    size_t i;

    for (i = 0; raw[i] != 0 && i < str->maxsize; i++)
        str->mem[i] = raw[i];

    str->size = i;

    if (raw[i] == 0) return 1; else return 0;
}

void str_copystr(string *dst, string src)
{
    size_t i;

    dst->size = src.size;
    for (i = 0; i < src.size; i++) {
        dst->mem[i] = src.mem[i];
    }
}

int str_cmp(string s1, string s2)
{
    size_t i;

    if (s1.size != s2.size) return 0;

    for (i = 0; i < s1.size; i++)
        if (s1.mem[i] != s2.mem[i]) break;

    return i == s1.size;
}

int str_ncmp(string s1, string s2, size_t n)
{
    size_t i;

    for (i = 0; i < n; i++)
        if (s1.mem[i] != s2.mem[i]) break;

    return i == n;
}

int str_cat(string *s1, string s2)
{
    size_t i;

    for (i = 0; i < s2.size; i++)
        s1->mem[s1->size+i] = s2.mem[i];

    s1->size += s2.size;
}

