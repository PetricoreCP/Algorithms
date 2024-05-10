vector <bool> Sieve(int n) {
    vector <bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;
    for(int p = 2; p * p <= n; p ++) {
        if(sieve[p]) {
            for(int m = p * p; m <= n; m += p) {
                sieve[m] = false;
            }
        }
    }
    return sieve;
}
