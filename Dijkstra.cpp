vector<long long> Dijkstra(vector<vector<pair<int, long long>>> & adj, int node) {
    int n = adj.size();
    vector<long long> cost(n, LLONG_MAX);
    cost[node] = 0;
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> pq;
    pq.push(make_pair(0, node));
    while(!pq.empty()) {
        auto [currWeight, curr] = pq.top();
        pq.pop();
        if(currWeight > cost[curr]) continue;
        for(auto [next, nextWeight] : adj[curr]) {
            if(cost[next] > nextWeight + currWeight) {
                cost[next] = nextWeight + currWeight;
                pq.push(make_pair(cost[next], next));
            }
        }
    }
    return cost;
}
