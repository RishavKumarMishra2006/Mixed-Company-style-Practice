#include <stdio.h>

int s1[1000], s2[1000];
int top1 = -1, top2 = -1;

void enqueue(int x) {
    s1[++top1] = x;
}

int dequeue() {
    if (top2 == -1) {
        while (top1 != -1)
            s2[++top2] = s1[top1--];
    }
    return s2[top2--];
}

int front() {
    if (top2 == -1) {
        while (top1 != -1)
            s2[++top2] = s1[top1--];
    }
    return s2[top2];
}
