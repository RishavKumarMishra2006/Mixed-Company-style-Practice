#include <stdio.h>

int largestRectangle(int arr[], int n) {
    int stack[1000], top = -1, max = 0, i = 0;

    while (i < n) {
        if (top == -1 || arr[stack[top]] <= arr[i])
            stack[++top] = i++;
        else {
            int h = arr[stack[top--]];
            int w = (top == -1) ? i : i - stack[top] - 1;
            if (h * w > max) max = h * w;
        }
    }

    while (top != -1) {
        int h = arr[stack[top--]];
        int w = (top == -1) ? i : i - stack[top] - 1;
        if (h * w > max) max = h * w;
    }

    return max;
}
