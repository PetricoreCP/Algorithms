#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

pair<vector<ll>, bool> bellmanFord(vector<tuple<int, int, ll>> &edges, int n, int start) {
    bool negativeCylce = false;
    vector<ll> distance(n, INF);
    distance[start] = 0ll;
    for(int i = 0; i < n; i ++) {
        for(auto &edge : edges) {
            int u, v;
            ll w;
            tie(u, v, w) = edge;
            //Negative Cylce detection
            if(i == n - 1) {
                if(distance[u] + w < distance[v]) negativeCylce = true;
            }
            distance[v] = min(distance[v], distance[u] + w);
        }
    }
    return make_pair(distance, negativeCylce);
}

void testCase() {
    int n, m; cin >> n >> m;
    vector<tuple<int, int, ll>> edges(m);
    for(int i = 0; i < m; i ++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u --; v --;
        edges[i] = make_tuple(u, v, w);
    }
    pair<vector<ll>, bool> distance = bellmanFord(edges, n, 0);
    if(distance.second) cout << "Negative Cycle Detected\n";
    for(int i = 0; i < n; i ++) cout << distance.first[i] << ' ';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc = 1; //cin >> tc;
    while(tc --) testCase();
    return 0;
}
