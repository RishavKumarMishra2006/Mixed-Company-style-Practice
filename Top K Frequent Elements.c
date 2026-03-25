#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

void topK(int arr[], int n, int k) {
    int freq[1000] = {0};

    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    int result[1000], idx = 0;

    for (int i = 0; i < 1000; i++) {
        if (freq[i] > 0)
            result[idx++] = i;
    }

    // sort by frequency
    for (int i = 0; i < idx; i++) {
        for (int j = i + 1; j < idx; j++) {
            if (freq[result[j]] > freq[result[i]]) {
                int temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }

    for (int i = 0; i < k; i++)
        printf("%d ", result[i]);
}
