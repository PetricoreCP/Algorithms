#include <bits/stdc++.h>
using namespace std;

using i32 = int32_t;
using i64 = int64_t;

using vi64 = vector<i64>;

#define SZ(x)         i32((x).size())
#define RSZ(x, n)     (x).resize(n)

#define F0R(i, n)     for(i32 i = 0; i < n; i ++)
#define FOR(i, a, b)  for(i32 i = a; i < b; i ++)

struct FenwickTree {
    i32 n;
    vi64 bit;

    FenwickTree(i32 n) {
        this->n = n + 1;
        RSZ(bit, n + 1);
    }

    FenwickTree(vi64 &a) : FenwickTree(SZ(a)) {
        FOR(i, 1, SZ(a) + 1) {
            bit[i] = a[i - 1];
            i32 r = i + (i & -i);
            if(r < SZ(a) + 1) {
                bit[r] += bit[i];
            }
        }
    }

    i64 sum(i32 i) {
        i64 tot = 0;
        while(i) {
            tot += bit[i];
            i -= i & -i;
        }
        return tot;
    }

    void add(i32 i, i64 x) {
        while(i < bit.size()) {
            bit[i] += x;
            i += i & -i;
        }
    }

    i64 getSum(i32 l, i32 r) {
        return sum(r) - sum(l - 1);
    }
};

void solve() {
    i32 n, q;
    cin >> n >> q;

    vi64 a(n);
    F0R(i, n) {
        cin >> a[i];
    }

    FenwickTree bit(a);

    F0R(i, q) {
        i32 t;
        cin >> t;

        if(t == 1) {
            i32 l, r;
            cin >> l >> r;

            cout << bit.getSum(l, r) << '\n';
        }
        else if(t == 2) {
            i32 j;
            cin >> j;

            i64 x;
            cin >> x;

            bit.add(j, x);
        }
    }
}   

i32 main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    i64 tc = 1ll;
    //cin >> tc;

    while(tc--) {
        solve();
    }

    return 0;
}
