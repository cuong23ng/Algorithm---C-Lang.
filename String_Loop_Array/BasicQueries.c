#include <stdio.h>

int main() {
    int n, k;
    int a[100000];
    int c=0;
    int sum = 0;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(i == k-1){
            for(int j = 0; j < k; j++){
                sum = sum + a[i-j];
            }
            if(sum % 2 == 0)c++;
        }
        else if(i > k-1){
            sum = sum - a[i-k] + a[i];
            if(sum % 2 == 0)c++;
        }
    }
    printf("%d", c);
    return 0;
}