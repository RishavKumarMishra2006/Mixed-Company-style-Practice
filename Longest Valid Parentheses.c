#include <stdio.h>

int longestValid(char* s) {
    int stack[1000], top = -1, max = 0;
    stack[++top] = -1;

    for (int i = 0; s[i]; i++) {
        if (s[i] == '(')
            stack[++top] = i;
        else {
            top--;
            if (top == -1)
                stack[++top] = i;
            else {
                int len = i - stack[top];
                if (len > max) max = len;
            }
        }
    }
    return max;
}
