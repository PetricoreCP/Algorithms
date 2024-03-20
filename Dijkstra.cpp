#include <iostream>
#include <vector>
#include <utility>
#include <queue>

template <typename T, typename U>
std::vector <long long> Dijkstra(T start, std::vector <std::vector <std::pair <T, U>>> & adj) {
    // Implementing ...
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
        std::cout << dist[next] << ' ';
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
