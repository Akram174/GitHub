/* big2.c
 * Simple program to print the larger of two numbers (supports integer or float input).
 * Compile: gcc -o big2 big2.c
 * Run:
 *   ./big2          -> prompts for input
 *   ./big2 3 5      -> uses command-line args
 *
 * Author: (you)
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* parse_double:
 *  - Parse a C string to double.
 *  - On error, prints message and exits.
 */
double parse_double(const char *s) {
    char *end;
    errno = 0;
    double val = strtod(s, &end);
    if (errno != 0) {
        perror("strtod");
        exit(EXIT_FAILURE);
    }
    if (end == s || *end != '\0') {
        fprintf(stderr, "Invalid number: '%s'\n", s);
        exit(EXIT_FAILURE);
    }
    return val;
}

int main(int argc, char *argv[]) {
    double a, b;

    if (argc == 3) {
        /* Use command-line arguments */
        a = parse_double(argv[1]);
        b = parse_double(argv[2]);
    } else {
        /* Interactive prompt */
        printf("Enter first number: ");
        if (scanf("%lf", &a) != 1) {
            fprintf(stderr, "Failed to read first number\n");
            return EXIT_FAILURE;
        }
        printf("Enter second number: ");
        if (scanf("%lf", &b) != 1) {
            fprintf(stderr, "Failed to read second number\n");
            return EXIT_FAILURE;
        }
    }

    if (a > b) {
        printf("Bigger: %g\n", a);
    } else if (b > a) {
        printf("Bigger: %g\n", b);
    } else {
        printf("Both numbers are equal: %g\n", a);
    }

    return 0;
}

