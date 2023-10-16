#include <stdio.h>

int n;
int b[20];
int stop;

void init(){
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        b[i] = 0;
    }

    stop = 0;
}

void Next_Bit_String(){
    int i;
    i = n - 1;

    while(i >= 0 && b[i] == 1){
        b[i] = 0;
        i--;
    }

    if(i < 0) stop = 1;
    else b[i] = 1;
}

int main()
{
    init();
    while(stop != 1){
        for(int i = 0; i < n; i++){
            printf("%d", b[i]);
        }
        printf("\n");
        Next_Bit_String();
    }
    return 0;
