#include "diostring.h"

#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>

int main(void)
{
    string s1, s2;
    int result;

    const char s_helloworld[] = "hello, world";

    s1.mem = malloc(sizeof(char) * 32);
    s1.maxsize = 32;
    s1.size = 0;

    printf("TEST 1: Copy from raw string...");
    result = str_copyraw(&s1, s_helloworld);

    assert(result == 1);
    assert(strncmp(s1.mem, s_helloworld, s1.size) == 0);
    assert(s1.size == strlen(s_helloworld));

    free(s1.mem);
    s1.maxsize = 0;
    s1.size = 0;

    printf("PASS\n");


    s1.mem = malloc(sizeof(char) * 5);
    s1.maxsize = 5;
    s1.size = 0;

    s2.mem = malloc(sizeof(char) * 5);
    s2.maxsize = 5;
    s2.size = 0;

    str_copyraw(&s1, "str1");
    str_copyraw(&s2, "str2");

    printf("TEST 2: Compare two strings...");
    assert(str_cmp(s1, s2) == 0);
    printf("PASS\n");

    printf("TEST 3: Compare first n characters of two strings...");
    assert(str_ncmp(s1, s2, 3) == 1);
    assert(str_ncmp(s1, s2, 2) == 1);
    assert(str_ncmp(s1, s2, 1) == 1);
    assert(str_ncmp(s1, s2, 4) == 0);
    printf("PASS\n");

    free(s1.mem);
    free(s2.mem);

    s1.size = s1.maxsize = 0;
    s2.size = s2.maxsize = 0;

    s1.mem = malloc(sizeof(char) * 10);
    s1.maxsize = 10;
    s1.size = 0;

    s2.mem = malloc(sizeof(char) * 5);
    s2.maxsize = 5;
    s2.size = 0;

    str_copyraw(&s1, "abcd");
    str_copyraw(&s2, "efgh");

    printf("TEST 4: Concatenate two strings...");
    str_cat(&s1, s2);
    assert(s1.size == 8);
    assert(strncmp(s1.mem, "abcdefgh", 8) == 0);
    printf("PASS\n");

    free(s1.mem);
    free(s2.mem);

    s1.size = s1.maxsize = 0;
    s2.size = s2.maxsize = 0;

    s1.mem = malloc(sizeof(char) * 20);
    s1.maxsize = 20;
    s1.size = 0;

    str_copyraw(&s1, "dank memes");

    printf("TEST 5: Find until...");

    string f = str_sliceuntil(s1, ' ');
    assert(f.size == strlen("dank"));
    assert(strncmp(f.mem, "dank", f.size) == 0);
    printf("PASS\n");

    free(s1.mem);
    s1.size = s1.maxsize = 0;

    return 0;
}
