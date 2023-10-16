#include <stdio.h>
#include <string.h>

int main() {
    int n;
    int a[10000];
    int sum = 0;
    int max = -1001, min = 1001;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        sum = sum + a[i];
        if(max < a[i]) max = a[i];
        if(min > a[i]) min = a[i];
    }
    char cmd[20];
    fflush(stdin);
    scanf("%s", &cmd);
    if(cmd[0] == '*'){
        do{
            fflush(stdin);
            scanf("%s", &cmd);
            if(!strcmp(cmd, "sum")) printf("%d\n", sum);
            if(!strcmp(cmd, "find-max")) printf("%d\n", max);
            if(!strcmp(cmd, "find-min")) printf("%d\n", min);
            if(!strcmp(cmd, "find-max-segment")){
                int start, end;
                int m = -1001;
                scanf("%d%d", &start, &end);
                for(int i = start-1; i <= end-1; i++){
                    if(a[i] > m) m = a[i];
                }
                printf("%d\n", m);
            }
        }while(strcmp(cmd, "***") != 0);
    }
    return 0;
}