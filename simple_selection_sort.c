/*
 * simple_selection_sort.c
 * A tiny, beginner-friendly demonstration of selection sort.
 *
 * Usage examples:
 *   Compile: gcc -std=c11 simple_selection_sort.c -o simple_selection_sort
 *   Run with arguments: ./simple_selection_sort 5 3 8 1
 *   Or run and type numbers: ./simple_selection_sort
 *     (then enter: 5 3 8 1 and press Enter)
 *
 * The program prints the array before sorting, and shows each step (which element is chosen
 * as the minimum and when a swap happens). Finally it prints the sorted array.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Print array of n integers on one line
void print_arr(int *a, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        if (i) putchar(' ');
        printf("%d", a[i]);
    }
    putchar('\n');
}

int main(int argc, char **argv) {
    int arr[128];       // fixed small buffer for simplicity
    size_t n = 0;

    if (argc > 1) {
        // parse command-line arguments as integers
        for (int i = 1; i < argc && n < sizeof(arr)/sizeof(arr[0]); ++i) {
            arr[n++] = atoi(argv[i]);
        }
    } else {
        // no arguments: prompt user to type numbers on one line
        char line[1024];
        printf("Enter integers separated by spaces (e.g. 5 3 8 1):\n");
        if (!fgets(line, sizeof(line), stdin)) return 0;
        char *tok = strtok(line, " \t\n\r");
        while (tok && n < sizeof(arr)/sizeof(arr[0])) {
            arr[n++] = atoi(tok);
            tok = strtok(NULL, " \t\n\r");
        }
    }

    if (n == 0) {
        printf("No numbers provided. Exiting.\n");
        return 0;
    }

    printf("Initial array: "); print_arr(arr, n);

    // Selection sort: for each position i, find smallest element in [i..n-1]
    for (size_t i = 0; i + 1 < n; ++i) {
        size_t min_idx = i;
        printf("\nStep %zu: start at index %zu, value %d\n", i+1, i, arr[i]);
        for (size_t j = i + 1; j < n; ++j) {
            printf("  Compare arr[%zu]=%d with current min arr[%zu]=%d\n", j, arr[j], min_idx, arr[min_idx]);
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
                printf("    New minimum found at index %zu (value %d)\n", min_idx, arr[min_idx]);
            }
        }
        if (min_idx != i) {
            printf("  Swapping arr[%zu]=%d and arr[%zu]=%d\n", i, arr[i], min_idx, arr[min_idx]);
            int tmp = arr[i]; arr[i] = arr[min_idx]; arr[min_idx] = tmp;
        } else {
            printf("  No swap needed (minimum already at index %zu)\n", i);
        }
        printf("Array now: "); print_arr(arr, n);
    }

    printf("\nSorted array: "); print_arr(arr, n);
    return 0;
}
{
    
}