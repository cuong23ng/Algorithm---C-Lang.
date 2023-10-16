#include <stdio.h>

int n;
int b[21];
int c[21];

void Init(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) c[i] = 1;
}

void Result(){
    for(int i = 1; i <= n; i++){
        printf("%d ", b[i]);
    }
    printf("\n");
}

void Try(int i){
    for(int j = 1; j <= n; j++){
        if(c[j]){
            b[i] = j;
            c[j] = 0;
            if(i == n) Result();
            else Try(i+1);
            c[j] = 1;
        }
    }
}

int main()
{
    Init();
    Try(1);
    return 0;
}