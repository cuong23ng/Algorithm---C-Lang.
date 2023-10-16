#include <stdio.h>

void convert(char t[]){
    char hh[5], mm[5], ss[5];
    int h, m, s;
    for(int i = 0; i < 2; i++){
        if(t[i] < '0' || t[i] > '9'){
            printf("INCORRECT");
            return;
        }
        hh[i] = t[i];
    }
    h = atoi(hh);
    if(h>23){
        printf("INCORRECT");
        return;
    }

    if(t[2] != ':'){
        printf("INCORRECT");
        return;
    }

    for(int i = 3; i < 5; i++){
        if(t[i] < '0' || t[i] > '9'){
            printf("INCORRECT");
            return;
        }
        mm[i-3] = t[i];
    }
    m = atoi(mm);
    if(m>59){
        printf("INCORRECT");
        return;
    }
    if(t[5] != ':'){
        printf("INCORRECT");
        return;
    }

    for(int i = 6; i < 8; i++){
        if(t[i] < '0' || t[i] > '9'){
            printf("INCORRECT");
            return;
        }
        ss[i-6] = t[i];
    }
    s = atoi(ss);
    if(s>59){
        printf("INCORRECT");
        return;
    }

    printf("%d", h*3600 + m*60 + s);
}

int main() {
    char t[10];
    scanf("%s", &t);
    convert(t);
    return 0;
}