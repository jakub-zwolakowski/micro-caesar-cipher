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
    if (!res2) {
        free(res1);
        return;
    }
    printf("Result:       %s\n", res2);

    free(res2);
    free(res1);
}

int test_1(void)
{
    char orig_str[] = "People of Earth, your attention please";

    printf("Test 1: Shift with a negative input\n");
    gen_test(orig_str, -3);
}

int test_2(void)
{
    char orig_str[] = "People of Earth, your attention please";

    printf("Test 2: Shift with a positive input\n");
    gen_test(orig_str, 7);
}

int test_3(void)
{
    char orig_str[] = "People of Earth, your attention please";

    printf("Test 3: Shift with INT_MIN\n");
    gen_test(orig_str, INT_MIN);
}


int test_suite(void)
{
    char orig_str[] = "People of Earth, your attention please";

    printf("Test 1: Shift with a negative input\n");
    gen_test(orig_str, -3);
    printf("\nTest 2: Shift with a positive input\n");
    gen_test(orig_str, 7);
    printf("\nTest 3: Shift with INT_MIN\n");
    gen_test(orig_str, INT_MIN);

    return 0;
}

#include <errno.h>
#include <string.h>

int int_of_string(const char *buff) {
    int shift = 0;
    errno = 0;
    char *endptr;
    long shift_long = strtol(buff, &endptr, 10);
    
    if (endptr == buff) {
        fprintf(stderr, "%s: not a decimal number\n", buff);
    } else if ('\0' != *endptr) {
        fprintf(stderr, "%s: extra characters at end of input: %s\n", buff, endptr);
    } else if ((LONG_MIN == shift_long || LONG_MAX == shift_long) && ERANGE == errno) {
        fprintf(stderr, "%s out of range of type long\n", buff);
    } else if (shift_long > INT_MAX) {
        fprintf(stderr, "%ld greater than INT_MAX\n", shift_long);
    } else if (shift_long < INT_MIN) {
        fprintf(stderr, "%ld less than INT_MIN\n", shift_long);
    } else {
        shift = (int)shift_long;
    }

    return shift;
}

int main(int argc, char **argv) {
    if(argc < 3) {
        return 1;
    }

    int shift = int_of_string(argv[1]);
    if (shift == 0) return 1;

    char *buff = argv[2];
    size_t len = strlen(buff);
    if(len > 100) {
        fprintf(stderr, "input string length %zu is greater than 100\n", len);
        return 1;
    }
    
    gen_test(buff, shift);

    return 0;
}