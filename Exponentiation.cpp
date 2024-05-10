long long ModExp(long long b, long long e, long long m) {
    long long r = 1;
    b %= m;
    while(e) {
        if(e & 1) {
            r = (r * b) % m;
            e --;
        }
        b = (b * b) % m;
        e >>= 1;
    }
    return r % m;
}
