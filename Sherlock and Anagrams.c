#include <stdio.h>
#include <string.h>

int isAnagram(char *a, char *b) {
    int count[26] = {0};

    for (int i = 0; a[i]; i++) {
        count[a[i] - 'a']++;
        count[b[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
        if (count[i] != 0) return 0;

    return 1;
}

int sherlock(char* s) {
    int n = strlen(s), count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int len = 1; len <= n - j; len++) {
                if (i + len <= n && j + len <= n) {
                    char a[100], b[100];
                    strncpy(a, s + i, len);
                    strncpy(b, s + j, len);
                    a[len] = b[len] = '\0';

                    if (isAnagram(a, b)) count++;
                }
            }
        }
    }
    return count;
}
