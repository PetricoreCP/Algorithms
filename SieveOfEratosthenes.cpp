#include <iostream>
#include <vector>

using namespace std;

vector <bool> Sieve(int n) {
    vector <bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for(int p = 2; p * p <= n; p ++) {
        if(prime[p]) {
            for(int m = p * p; m <= n; m += p) {
                prime[m] = false;
            }
        }
    }
    return prime;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", output);
    int tc = 1;
    //cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        vector <bool> prime = Sieve(n);
        for(int p = 2; p <= n; p ++) {
            if(prime[p]) {
                cout << p << ' ';
            }
        }
    }
    return 0;
}
