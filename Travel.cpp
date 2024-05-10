void Dfs(vector<vector<int>> & adj, int node) {
    int n = adj.size();
    stack<int> s;
    vector<bool> vis(n);
    s.push(node);
    vis[node] = true;
    while(!s.empty()) {
        node = s.top();
        s.pop();
        for(int next : adj[node]) {
            if(!vis[next]) {
                vis[next] = true;
                s.push(next);
            }
        }
    }
}

void Bfs(vector<vector<int>> & adj, int node) {
    int n = adj.size();
    queue<int> q;
    vector<bool> vis(n);
    q.push(node);
    vis[node] = true;
    while(!q.empty()) {
        node = q.front();
        q.pop();
        for(int next : adj[node]) {
            if(!vis[next]) {
                vis[next] = true;
                q.push(next);
            }
        }
    }
}
