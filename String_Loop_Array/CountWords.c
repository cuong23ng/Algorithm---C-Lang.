#include <stdio.h>

int main() {
    char s;
    int in = 0;
    int c = 0;

    while ((s = getchar()) != EOF) {
        if (s == ' ' || s == '\t' || s == '\n') {
            in = 0;
        } else if (!in) {
            in = 1;
            c++;
        }
    }

    printf("%d", c);

    return 0;
}