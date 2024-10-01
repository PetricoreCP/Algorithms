#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

vector<ll> bellmanFord(vector<tuple<int, int, ll>> &edges, int n, int start) {
    vector<ll> distance(n, INF);
    distance[start] = 0;
    bool detection = false;
    for(int i = 0; i < n - 1; i ++) {
        bool converged = true;
        for(auto &edge : edges) {
            int u, v;
            ll w;
            tie(u, v, w) = edge;
            if(distance[u] != INF && distance[v] > distance[u] + w) {
                distance[v] = distance[u] + w;
                converged = false;
            }
        }
        if(converged) break;
    }
    for(auto &edge : edges) {
        int u, v;
        ll w;
        tie(u, v, w) = edge;
        if(distance[v] > distance[u] + w) {
            detection = true;
            break;
        }
    }
    if(detection) distance[start] = -1;
    return distance;
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
    int start = 0;
    vector<ll> distance = bellmanFord(edges, n, start);
    if(distance[start] == -1) {
        cout << "Negative Cycle Detected\n";
        return;
    }
    for(int i = 0; i < n; i ++) {
        if(distance[i] == INF) cout << "Unreachable ";
        else cout << distance[i] << ' ';
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc = 1; //cin >> tc;
    while(tc --) testCase();
    return 0;
}
