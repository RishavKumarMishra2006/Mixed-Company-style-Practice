#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id, deadline, profit;
} Job;

int cmp(const void* a, const void* b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

void jobSequence(Job arr[], int n) {
    qsort(arr, n, sizeof(Job), cmp);

    int slot[100] = {0}, profit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = arr[i].deadline - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = 1;
                profit += arr[i].profit;
                break;
            }
        }
    }

    printf("Max Profit = %d\n", profit);
}
