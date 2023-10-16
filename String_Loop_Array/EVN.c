#include <stdio.h>

float cost(int n){
    if(n<=50) return 0;
    else if (n<=100) return  -58*(n-50);
    else if (n<=300) return -58*50;
    else if (n<=400) return -58*50+(2612-2919)*(n-300);
    else if (n<=700) return (1728-1786)*50+(2612-2919)*100+(3111-3015)*(n-400);
    else             return (1728-1786)*50+(2612-2919)*100+(3111-3015)*300+(3457-3015)*(n-700);
}

int main()
{
    int n;
    float sum;
    scanf("%d", &n);
    sum = cost(n);
    printf("%.2f",sum*1.1);
    return 0;
}