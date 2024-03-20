template <typename T>
vector <bool> Sieve(T n) {
    vector <bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for(T p = 2; p * p <= n; p ++) {
        if(prime[p]) {
            for(T m = p * p; m <= n; m += p) {
                prime[m] = false;
            }
        }
    }
    return prime;
}
