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
