#include <stdio.h>
#include <ctype.h>

int main() {
    char text[1000];
    while (fgets(text, sizeof(text), stdin) != NULL) {
        for (int i = 0; text[i]; i++) {
            putchar(toupper(text[i]));
        }
    }

    return 0;
}