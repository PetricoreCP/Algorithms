#include <bits/stdc++.h>

template <typename T>
T ModExp(T base, T exp, T mod) {
    T ans = 1;
    base %= mod;
    while(exp) {
        if(exp & 1) {
            ans = (ans * base) % mod;
            exp --;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return ans % mod;
}

void Main() {
    long long base, exp, mod;
    std::cin >> base >> exp >> mod;
    long long ans = ModExp(base, exp, mod);
    std::cout << ans;
}   

int main() {
    std::ios::sync_with_stdio(0); 
    std::cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1; 
    //std::cin >> t;
    while (t--) {
        Main();
    }
    return 0;
}