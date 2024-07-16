#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;

struct FenwickTree {
    i32 size;
    vector<i64> tree;

    FenwickTree(i32 n) {
        size = n + 1;
        tree.resize(size);
    }

    FenwickTree(vector<i64> &v) : FenwickTree(v.size()) {
        for(i32 i = 0; i < v.size(); i ++) {
            tree[i + 1] = v[i];
        }
        for(i32 i = 1; i < size; i ++) {
            i32 p = i + (i & -i);
            if(p < size) {
            	tree[p] += tree[i];
            }
        }
    }

    i64 prefix(i32 i) {
        i64 tot = 0;
        while(i) {
            tot += tree[i];
            i -= i & -i;
        }
        return tot;
    }

    void add(i32 i, i64 x) {
        while(i < size) {
            tree[i] += x;
            i += i & -i;
        }
    }

    i64 getSum(i32 l, i32 r) {
        return prefix(r) - prefix(l - 1);
    }
};
