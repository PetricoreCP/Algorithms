long long Gcd(long long a, long long b) {
    while(b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long Lcm(long long a, long long b) {
    if(!a || !b) return 0;
    return a / Gcd(a, b) * b;
}
