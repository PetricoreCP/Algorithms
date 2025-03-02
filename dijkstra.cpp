#include <bits/stdc++.h>
using namespace std;

vector<long long> dijkstra(const vector<vector<pair<int, long long>>>& adj, int root) {
    const long long INF = numeric_limits<long long>::max();

    vector<long long> distance(adj.size(), INF);
    distance[root] = 0LL;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minHeap;
    minHeap.push(make_pair(0LL, root));

    while (!minHeap.empty()) {
        auto [currDistance, node] = minHeap.top();
        minHeap.pop();

        if (distance[node] < currDistance) {
            continue;
        }

        for (auto& [next, weight]: adj[node]) {
            if (currDistance + weight < distance[next]) {
                distance[next] = currDistance + weight;
                minHeap.push(make_pair(distance[next], next));
            }
        }
    }

    return distance;
}
