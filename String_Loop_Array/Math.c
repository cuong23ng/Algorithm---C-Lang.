#include <stdio.h>

int main() {
    int n, x;
    int e, o;
    e = 0; o = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        if(x%2 == 0) e++;
        else o++;
    }
    printf("%d %d", o, e);
    return 0;
}