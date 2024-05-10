vector<long long> Dijkstra(vector<vector<pair<int, long long>>> & adj, int node) {
    int n = adj.size();
    vector<long long> cost(n, LLONG_MAX);
    cost[node] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push(make_pair(0, node));
    while(!pq.empty()) {
        pair<long long, int> p = pq.top();
        long long currWeight = p.first;
        int curr = p.second;
        pq.pop();
        if(currWeight > cost[curr]) continue;
        for(pair<int, long long> & q  : adj[curr]) {
            int next = q.first;
            long long nextWeight = q.second;
            if(cost[next] > nextWeight + currWeight) {
                cost[next] = nextWeight + currWeight;
                pq.push(make_pair(cost[next], next));
            }
        }
    }
    return cost;
}
