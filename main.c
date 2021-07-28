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
    char orig_str[] = "People of Earth";

    printf("Test 0: No bug on the execution path\n");
    gen_test(orig_str, 3);
}

void test_1(void)
{
    char orig_str[] = "People of Earth, your attention please";

    printf("Test 1: Shift with a negative input\n");
    gen_test(orig_str, -3);
}

void test_2(void)
{
    char orig_str[] = "People of Earth, your attention please";

    printf("Test 2: Shift with a positive input\n");
    gen_test(orig_str, 7);
}

void test_3(void)
{
    char orig_str[] = "People of Earth, your attention please";

    printf("Test 3: Shift with INT_MIN\n");
    gen_test(orig_str, INT_MIN);
}


void main(void)
{
    char orig_str[] = "People of Earth, your attention please";

    printf("Test 1: Shift with a negative input\n");
    gen_test(orig_str, -3);
    printf("\nTest 2: Shift with a positive input\n");
    gen_test(orig_str, 7);
    printf("\nTest 3: Shift with INT_MIN\n");
    gen_test(orig_str, INT_MIN);
}
