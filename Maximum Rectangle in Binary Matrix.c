#include <stdio.h>
#define MAX 100

int maxHist(int row[], int n) {
    int stack[MAX], top = -1, max = 0, i = 0;

    while (i < n) {
        if (top == -1 || row[stack[top]] <= row[i])
            stack[++top] = i++;
        else {
            int h = row[stack[top--]];
            int w = (top == -1) ? i : i - stack[top] - 1;
            if (h * w > max) max = h * w;
        }
    }

    while (top != -1) {
        int h = row[stack[top--]];
        int w = (top == -1) ? i : i - stack[top] - 1;
        if (h * w > max) max = h * w;
    }

    return max;
}

int maxRectangle(int M[][MAX], int R, int C) {
    int result = maxHist(M[0], C);

    for (int i = 1; i < R; i++) {
        for (int j = 0; j < C; j++)
            if (M[i][j])
                M[i][j] += M[i - 1][j];

        int area = maxHist(M[i], C);
        if (area > result) result = area;
    }
    return result;
}
