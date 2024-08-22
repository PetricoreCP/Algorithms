template<typename T> struct FenwickTree {
    int sz, msb = 1;
    vector<T> tree;


    FenwickTree(int n) {
        sz = n + 1;
        tree.resize(sz);
        while((msb << 1) <= sz) msb <<= 1;
    }

    FenwickTree(vector<T> &v) : FenwickTree(v.size()) {
        for(int i = 0; i < v.size(); i ++) tree[i + 1] = v[i];
        for(int i = 1; i < sz; i ++) {
            int j = i + (i & -i);
            if(j < sz) tree[j] += tree[i];
        }
    }


    void pointAdd(int i, T x) {
        while(i < sz) {
            tree[i] += x;
            i += i & -i;
        }
    }

    void pointUpdate(int i, T x) {
        T delta = x - getSum(i, i);
        pointAdd(i, delta);
    }

    T prefixSum(i32 i) {
        T res = 0;
        while(i > 0) {
            res += tree[i];
            i -= i & -i;
        }
        return res;
    }

    T getSum(int l, int r) {
        return prefixSum(r) - prefixSum(l - 1);
    }

    int lowerBound(T x) {
        int curr = 0; 
        T tot = 0;
        for(int bit = msb; bit > 0; bit >>= 1) {
            if((curr | bit) < sz && tot + tree[curr | bit] < x) {
                curr |= bit; 
                tot += tree[curr];
            }
        }
        if(tot < x) return -1;
        return curr + 1;
    }
};
