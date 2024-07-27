// Recursive Binary Exponentiation
long long binExp(long long base, long long exp) {
	if(exp == 0) return 1;
	long long tmp = binExp(base, exp / 2);
	if(exp % 2) return tmp * tmp * base;
	return tmp * tmp;
}	

// Iterative Binary Exponentiation
long long binExp(long long base, long long exp) {
	long long ans = 1;
	while(exp) {
		if(exp & 1) ans *= base;
		base *= base;
		exp >>= 1;
	}
	return ans;
}

// Iterative Binary Modular Exponentiation
long long binModExp(long long base, long long exp, long long mod) {
	long long ans = 1;
	base %= mod;
	while(exp) {
		if(exp & 1) ans = ans * base % mod;
		base = base * base % mod; 
		exp >>= 1;
	}
	return ans;
}

// Applying a permutation k times
vector<long long> apply(vector<long long> sequence, vector<long long> permutation) {
	int n = sequence.size();
    vector<long long> res(n);
    for(int i = 0; i < n; i ++) {
        res[i] = sequence[permutation[i]];
    }
    return res;
}

vector<long long> permute(vector<long long> sequence, vector<long long> permutation, long long k) {
    while(k) {
        if(k & 1) sequence = apply(sequence, permutation);
        permutation = apply(permutation, permutation);
        k >>= 1;
    }
    return sequence;
}
