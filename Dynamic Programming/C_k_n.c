#include <stdio.h>

#define MOD 1000000007

// Function to calculate the modular exponentiation a^b % MOD
long long inv(long long a, long long b) {
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

long long ChinhHop(int k, int n) {
    long long k_gt = 1;
    long long n_k_gt = 1;
    long long n_gt = 1;

    for (int i = 1; i <= k; i++) {
        k_gt = (k_gt * i) % MOD;
    }

    for (int i = 1; i <= n - k; i++) {
        n_k_gt = (n_k_gt * i) % MOD;
    }

    for (int i = 1; i <= n; i++) {
        n_gt = (n_gt * i) % MOD;
    }

    return (n_gt * inv((k_gt * n_k_gt) % MOD, MOD - 2)) % MOD;

}

int main() {
    int k, n;
    scanf("%d %d", &k, &n);

    printf("%lld", ChinhHop(k, n));

    return 0;
}