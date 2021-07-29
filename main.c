#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "caesar.h"

void gen_test(char *str, int shift)
{
    char *res1, *res2;

    printf("Encrypt text '%s'\n", str);
    res1 = caesar_encrypt(str, shift);
    if (!res1) return;
    printf("Result:       %s\n", res1);

    printf("Decrypt text '%s'\n", res1);
    res2 = caesar_decrypt(res1, shift);
    if (!res2) goto l;
    printf("Result:       %s\n", res2);

    free(res2);
l:  free(res1);
}

void test_0(void)
{
    char str[] = "People of Earth";

    printf("\nTest 0: Short string\n");
    gen_test(str, 3);
}

void test_1(void)
{
    char str[] = "People of Earth, your attention please";

    printf("\nTest 1: Shift with a negative input\n");
    gen_test(str, -3);
}

void test_2(void)
{
    char str[] = "People of Earth, your attention please";

    printf("\nTest 2: Shift with a positive input\n");
    gen_test(str, 7);
}

void test_3(void)
{
    char str[] = "People of Earth, your attention please";

    printf("\nTest 3: Shift with INT_MIN\n");
    gen_test(str, INT_MIN);
}

void test_4(void)
{
    char str[] = "People of Earth, your attention please";

    printf("\nTest 4: Shift with INT_MAX\n");
    gen_test(str, INT_MAX);
}

void main(void)
{
    test_0();
    test_1();
    test_2();
    test_3();
    test_4();
}
