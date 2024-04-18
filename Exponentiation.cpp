#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

template <typename T, typename U, typename V>
T ModExp(U base, V exp, T mod) {
    T res = 1;
    base %= mod;
    while(exp) {
        if(exp & 1) {
            res = (res * base) % mod;
            exp --;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", output);
    int tc = 1;
    //cin >> tc;
    while(tc--) {
        long long base, exp;
        cin >> base >> exp;
        cout << ModExp(base, exp, mod);
    }
    return 0;
}
