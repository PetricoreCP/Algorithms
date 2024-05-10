vector <bool> Sieve(int n) {
    vector <bool> v(n + 1, true);
    v[0] = v[1] = false;
    for(int p = 2; p * p <= n; p ++) {
        if(v[p]) {
            for(int m = p * p; m <= n; m += p) {
                v[m] = false;
            }
        }
    }
    return v;
}
