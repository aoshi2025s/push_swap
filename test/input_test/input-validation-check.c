// this is test for input-validation-check

// intput_to_stack(int size, char **string);
// is_integer(char *str);
// is_exist_num(int num, int *numbers, int end);

#include <stdio.h>

int is_integer(char *str);
int is_exist_num(int num, int *numbers, int end);

void input_validation_check(void)
{
    int test_ok = 1;
    // ANSI color codes
    const char *red = "\033[1;31m";
    const char *green = "\033[1;32m";
    const char *reset = "\033[0m";

    // is_integer check 
    if (is_integer("2147483647") == 0) {
        test_ok = 0;
        printf("%s%-25s %15s%s\n", red, "2147483647", "test failed", reset);
    } else {
        printf("%s%-25s %15s%s\n", green, "2147483647", "test passed", reset);
    }
    if (is_integer("") == 1) {
        test_ok = 0;
        printf("%s%-25s %15s%s\n", red, "Empty string", "test failed", reset);
    } else {
        printf("%s%-25s %15s%s\n", green, "Empty string", "test passed", reset);
    }
    if (is_integer("2147483648") == 1) {
        test_ok = 0;
        printf("%s%-25s %15s%s\n", red, "2147483648", "test failed", reset);
    } else {
        printf("%s%-25s %15s%s\n", green, "2147483648", "test passed", reset);
    }
    if (is_integer("-2147483648") == 0) {
        test_ok = 0;
        printf("%s%-25s %15s%s\n", red, "-2147483648", "test failed", reset);
    } else {
        printf("%s%-25s %15s%s\n", green, "-2147483648", "test passed", reset);
    }
    if (is_integer("-2147483649") == 1) {
        test_ok = 0;
        printf("%s%-25s %15s%s\n", red, "-2147483649", "test failed", reset);
    } else {
        printf("%s%-25s %15s%s\n", green, "-2147483649", "test passed", reset);
    }
    if (is_integer("321a") == 1) {
        test_ok = 0;
        printf("%s%-25s %15s%s\n", red, "321a", "test failed", reset);
    } else {
        printf("%s%-25s %15s%s\n", green, "321a", "test passed", reset);
    }
    if (is_integer("abcde") == 1) {
        test_ok = 0;
        printf("%s%-25s %15s%s\n", red, "abcde", "test failed", reset);
    } else {
        printf("%s%-25s %15s%s\n", green, "abcde", "test passed", reset);
    }
    if (is_integer("+215") == 0) {
        test_ok = 0;
        printf("%s%-25s %15s%s\n", red, "+215", "test failed", reset);
    } else {
        printf("%s%-25s %15s%s\n", green, "+215", "test passed", reset);
    }
    if (is_integer("++215") == 1) {
        test_ok = 0;
        printf("%s%-25s %15s%s\n", red, "++215", "test failed", reset);
    } else {
        printf("%s%-25s %15s%s\n", green, "++215", "test passed", reset);
    }

    // duplicate check
    int nums1[] = {1, 2, 3, 4};
    if (is_exist_num(5, nums1, 4) == 1) {
        test_ok = 0;
        printf("%s%-25s %15s%s\n", red, "Number 5 in array", "test failed", reset);
    } else {
        printf("%s%-25s %15s%s\n", green, "Number 5 in array", "test passed", reset);
    }
    int nums2[] = {1, 3, 4};
    if (is_exist_num(1, nums2, 3) == 0) {
        test_ok = 0;
        printf("%s%-25s %15s%s\n", red, "Number 1 in array", "test failed", reset);
    } else {
        printf("%s%-25s %15s%s\n", green, "Number 1 in array", "test passed", reset);
    }
    int nums3[] = {3, 1, 2, 4};
    if (is_exist_num(3, nums3, 4) == 0) {
        test_ok = 0;
        printf("%s%-25s %15s%s\n", red, "Number 3 in array", "test failed", reset);
    } else {
        printf("%s%-25s %15s%s\n", green, "Number 3 in array", "test passed", reset);
    }

    if (test_ok == 1)
        printf("%s%-25s %15s%s\n", green, "All tests", "passed", reset);
    else
        printf("%s%-25s %15s%s\n", red, "Some tests", "failed", reset);
}



int main(void)
{
    input_validation_check();
}