#include <bits/stdc++.h>
using namespace std;

using i32 = int32_t;
using i64 = int64_t;

using vi32 = vector<i32>;

#define FOR(i, a, b) for(i32 i = a; i < b; i ++)
#define AUTO(a, x) for(auto &a : x)

vi32 z_function(string & s) {
    i32 n = s.length(), l = 0, r = 0;
    vi32 z(n);

    FOR(i, 1, n) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i] ++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    
    return z;
}

void solve() {
    string s;
    cin >> s;

    vi32 z = z_function(s);

    AUTO(x, z) {
        cout << x << ' ';
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
