#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

void floydWarshall(vector<vector<ll>> &matrix, int n) {
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            for(int k = 0; k < n; k ++) {
                matrix[j][k] = min(matrix[j][k], matrix[j][i] + matrix[i][k]);
            }
        }
    }
}

void testCase() {
    int n, m; cin >> n >> m;
    vector<vector<ll>> matrix(n, vector<ll>(n, INF));
    for(int i = 0; i < m; i ++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u --; v --;
        matrix[u][v] = w;
        matrix[v][u] = w;
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(i == j) matrix[i][j] = 0ll;
        }
    }
    floydWarshall(matrix, n);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc = 1; //cin >> tc;
    while(tc --) testCase();
    return 0;
}
