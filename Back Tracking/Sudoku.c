#include <stdio.h>

int b[10][10];
int r[10][10];
int c[10][10];
int s[10][10];
int count;

void Init(){
    for(int i = 1; i <= 9; i++)
        for(int j = 1; j <= 9; j++){
            r[i][j] = 1;
            c[i][j] = 1;
            s[i][j] = 1;
        }


    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            scanf("%d", &b[i][j]);

            if(b[i][j] != 0){
                r[i][b[i][j]] = 0;
                c[j][b[i][j]] = 0;
                s[(j-1)/3 + (i-1)/3 * 3 + 1][b[i][j]] = 0;
            }
        }
    }
    count = 0;
}

void Result(){
    count++;
}

void Try(int k, int g){
    //if(k < 10 && g < 10){
    if(b[k][g] == 0){
        //printf("hi ");
    //for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
                if(r[k][j] && c[g][j] && s[(g-1)/3 + (k-1)/3 * 3 + 1][j]){
                    //printf("(%d, %d):%d, ", k, g, j);
                    //b[k][g] = j;
                    r[k][j] = 0;
                    c[g][j] = 0;
                    s[(g-1)/3 + (k-1)/3 * 3 + 1][j] = 0;
                    if(k == 9 && g == 9) Result();
                    else if(g < 9) Try(k, g+1);
                    else if(g == 9) Try(k+1, 1);
                    r[k][j] = 1;
                    c[g][j] = 1;
                    s[(g-1)/3 + (k-1)/3 * 3 + 1][j] = 1;
                }
        }
    }
    else {
        //printf("no ");
        if(k == 9 && g == 9) Result();
        else if(g < 9) Try(k, g+1);
        else if(g == 9) Try(k+1, 1);
    }
}

int main()
{
    Init();
    Try(1, 1);
    printf("%d", count);
    return 0;
}