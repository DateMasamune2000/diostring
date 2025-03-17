#ifndef _DIOSTRING_H
#define _DIOSTRING_H

#include <stddef.h>

typedef struct string {
    char *mem;
    size_t size;
    size_t maxsize;
} string;

int str_copyraw(string *str, const char *raw);

int str_cmp(string s1, string s2);
int str_ncmp(string s1, string s2, size_t n);

int str_cat(string *s1, string s2);

#endif
