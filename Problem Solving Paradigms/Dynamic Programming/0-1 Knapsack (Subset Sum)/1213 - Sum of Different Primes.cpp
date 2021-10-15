#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> primes;
vector<vector<int>> dp;
int sz;

void sieve() {
    bitset<1120> isPrime;
    isPrime.set();
    for (int i = 2; i * i <= 1120; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= 1120; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= 1120; i++) {
        if (isPrime[i]) {
            primes.emplace_back(i);
        }
    }
    sz = primes.size();
}

void build() {
    dp.assign(1121, vector<int>(15));
    dp[0][0] = 1;
    for (int i = 0; i < sz; i++) {
        for (int j = 1120; j >= primes[i]; j--) {
            for (int k = 14; k >= 1; k--) {
                dp[j][k] += dp[j - primes[i]][k - 1];
            }
        }
    }
}

int32_t main() {
    /*ifstream fin("input.txt");
    ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    build();
    int n, k;
    while (cin >> n >> k, n) {
        cout << dp[n][k] << "\n";
    }
    /*fin.close();
    fout.close();*/
    return 0;
}