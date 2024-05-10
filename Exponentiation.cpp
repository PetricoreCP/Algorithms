long long ModExp(long long base, long long exp, long long mod) {
    long long res = 1;
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
