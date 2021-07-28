#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

void gen_test(char *str, int shift);

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
    if(argc < 3 || argv == NULL || argv[1] == NULL || argv[2] == NULL) {
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