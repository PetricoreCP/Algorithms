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
