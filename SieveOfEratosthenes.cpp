template <typename T>
vector <T> Sieve(T n) {
    vector <T> ans;
    vector <bool> prime(n + 1, true);
    for(T p = 2; p * p <= n; p ++) {
        if(prime[p]) {
            for(T m = p * p; m <= n; m += p) {
                prime[m] = false;
            }
        }
    }
    for(T p = 2; p <= n; p ++) {
        if(prime[p]) {
            ans.push_back(p);
        }
    }
    return ans;
}