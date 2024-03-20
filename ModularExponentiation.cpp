#include <iostream>

template <typename T>
T ModExp(T base, T exp, T mod) {
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

void Main() {
    long long base, exp, mod;
    std::cin >> base >> exp >> mod;

    std::cout << ModExp(base, exp, mod);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", output);
    
    int t = 1;
    //std::cin >> t;

    while(t--) {
        Main();
    }

    return 0;
}
