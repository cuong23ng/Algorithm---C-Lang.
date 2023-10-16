//C
#include <stdio.h>

int main()
{
    int n, s;
    scanf("%d", &n);
    if(100 % n == 0) s = 100;
    else s = (100/n + 1) * n;
    while(s < 1000){
        printf("%d", s);
        s = s + n;
        printf(" ");
    }
    return 0;
}