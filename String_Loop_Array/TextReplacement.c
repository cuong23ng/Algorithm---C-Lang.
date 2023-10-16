#include <stdio.h>
#include <string.h>

int main() {
    char p1[1001];
    char p2[1001];
    char t[10001];

    fgets(p1, sizeof(p1), stdin);
    p1[strlen(p1) - 1] = '\0';

    fgets(p2, sizeof(p2), stdin);
    p2[strlen(p2) - 1] = '\0';

    fgets(t, sizeof(t), stdin);

    char res[10001];
    int l = 0;

    for (int i = 0; i < strlen(t); i++) {
        int m = 1;
        for (int j = 0; j < strlen(p1); j++) {
            if (t[i + j] != p1[j]) {
                m = 0;
                break;
            }
        }

        if (m) {
            for (int j = 0; j < strlen(p2); j++) {
                res[l++] = p2[j];
            }
            i += strlen(p1) - 1;
        } else {
            res[l++] = t[i];
        }
    }

    res[l] = '\0';

    printf("%s", res);

    return 0;
}