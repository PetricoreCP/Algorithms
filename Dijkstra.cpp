#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <limits>

using namespace std;

template <typename T, typename U>
vector <U> Dijkstra(T start, std::vector <std::vector <std::pair <T, U>>> & adj) {
    vector <U> dist(adj.size(), numeric_limits <U>::max());
    dist[start] = 0;
    priority_queue <std::pair <U, T>, vector <pair <U, T>>, greater <pair <U, T>>> pq;
    pq.push(make_pair(0, start));
    while(!pq.empty()) {
        auto [w, e] = pq.top();
        pq.pop();
        if(w > dist[e]) continue;
        for(auto [next, nw] : adj[e]) {
            if(dist[next] > nw + w) {
                dist[next] = nw + w;
                pq.push(make_pair(dist[next], next));
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", output);
    int tc = 1;
    //cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
        vector <vector <pair <int, long long>>> adj(n);
        for(int i = 0; i < m; i ++) {
            int a, b, w;
            cin >> a >> b >> w;
            a --; b --;
            adj[a].push_back(make_pair(b, w));
            adj[b].push_back(make_pair(a, w));
        }
        vector <long long> dist = Dijkstra(0, adj);
    }
    return 0;
}
