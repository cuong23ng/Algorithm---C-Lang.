#include <stdio.h>

int main()
{
    int n;
    int a[50];
    a[0] = 0;
    a[1] = 1;
    scanf("%d", &n);
    for(int i = 2; i < n; i++){
        a[i] = a[i-1] + a[i-2];
    }
    printf("%d", a[n-1]);
}