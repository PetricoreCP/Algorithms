#include <bits/stdc++.h>
using namespace std;

using i32 = int32_t;
using i64 = int64_t;

const i64 INF64 = 1e18;

vector<i64> dijkstra(vector<vector<pair<i32, i64>>> &adj, i32 start) {
    i32 n = adj.size();
    vector<i64> cost(n, INF64);
    cost[start] = 0;
    priority_queue<pair<i64, i32>, vector<pair<i64, i32>>, greater<pair<i64, i32>>> pq;
    pq.push(make_pair(0, start));
    while(!pq.empty()) {
        pair<i64, i32> p = pq.top();
        pq.pop();
        i64 c = p.first;
        i32 node = p.second;
        if(c > cost[node]) continue;
        for(auto &q : adj[node]) {
            i32 next = q.first;
            i64 w = q.second;
            if(c + w < cost[next]) {
                cost[next] = c + w;
                pq.push(make_pair(cost[next], next));
            }
        }
    }
    return cost;
}

void solve() {
    i32 n, m;
    cin >> n >> m;
    vector<vector<pair<i32, i64>>> adj(n);
    for(i32 i = 0; i < m; i ++) {
        i32 u, v;
        i64 w;
        cin >> u >> v >> w;
        u --; v --;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    vector<i64> cost = dijkstra(adj, 0);
    for(auto &x : cost) {
        cout << x << ' ';
    }
}

i32 main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 tc = 1ll;
    //cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}
