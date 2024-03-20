#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <limits>

template <typename T, typename U>
std::vector <U> Dijkstra(T start, std::vector <std::vector <std::pair <T, U>>> & adj) {
    std::vector <U> dist(adj.size() + 1, std::numeric_limits <U>::max());
    dist[start] = 0;

    std::priority_queue <std::pair <U, T>, std::vector <std::pair <U, T>>, std::greater <std::pair <U, T>>> pq;
    pq.push(std::make_pair(0, start));

    while(!pq.empty()) {
        auto [w, e] = pq.top();
        pq.pop();
        if(w > dist[e]) continue;
        for(auto [next, nw] : adj[e]) {
            if(dist[next] > nw + w) {
                dist[next] = nw + w;
                pq.push(std::make_pair(dist[next], next));
            }
        }
    }

    return dist;
}

void Main() {
    int n, m;
    std::cin >> n >> m;

    std::vector <std::vector <std::pair <int, long long>>> adj(n + 1);
    for(int i = 0; i < m; i ++) {
        int a, b, w;
        std::cin >> a >> b >> w;
        adj[a].push_back(std::make_pair(b, w));
        adj[b].push_back(std::make_pair(a, w));
    }

    std::vector <long long> dist = Dijkstra(1, adj);
    for(int next = 1; next <= n; next ++) {
        if(dist[next] < std::numeric_limits <long long>::max()) {
            std::cout << dist[next] << ' ';
        }
        else {
            std::cout << -1 << ' ';
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", output);
    
    int t = 1;
    //std::cin >> t;

    while(t--) {
        Main();
    }

    return 0;
}
