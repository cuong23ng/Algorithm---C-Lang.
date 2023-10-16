#include <stdio.h>

int n;
int b[20];

void Result(){
    for(int i = 0; i < n; i++){
        printf("%d", b[i]);
    }
    printf("\n");
}

void Try(int i){
    for(int j = 0; j <= 1; j++){
        if(b[i-1] == 1 && j == 1) break;
        b[i] = j;
        if(i == n-1) Result();
        else Try(i+1);
    }
}

int main()
{
    scanf("%d", &n);
    Try(0);
    return 0;
}