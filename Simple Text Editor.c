#include <stdio.h>
#include <string.h>

char str[100000];
char history[1000][1000];
int top = -1;

void append(char *s) {
    strcpy(history[++top], str);
    strcat(str, s);
}

void delete(int k) {
    strcpy(history[++top], str);
    int len = strlen(str);
    str[len - k] = '\0';
}

void undo() {
    if (top >= 0)
        strcpy(str, history[top--]);
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            char s[1000];
            scanf("%s", s);
            append(s);
        } else if (type == 2) {
            int k;
            scanf("%d", &k);
            delete(k);
        } else if (type == 3) {
            int k;
            scanf("%d", &k);
            printf("%c\n", str[k - 1]);
        } else {
            undo();
        }
    }
}
