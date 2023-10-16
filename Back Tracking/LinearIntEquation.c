#include <stdio.h>

int n, m;
int b[21];
//int c[21];

void Init(){
    scanf("%d%d", &n, &m);
    //for(int i = 1; i < m; i++) c[i] = 1;
}

void Result(){
    for(int i = 1; i <= n; i++){
        printf("%d ", b[i]);
    }
    printf("\n");
}

void Try(int i, int s){
    //printf("%d\n", s);
    for(int j = 1; j < s; j++){
        if(s - j > 0){
            b[i] = j;
            if(i == n - 1) {
                    b[i+1] = s - j;
                    Result();
            }
            else Try(i+1, s-j);
        }
    }
}

int main()
{
    Init();
    Try(1, m);
    return 0;
}