class BinaryLifting {
private:
    int n, maxDepth = 0, maxStep = 0;
    vector<int> parents, depths;
    vector<vector<int>> trans;

    void Dfs(vector<vector<int>> & adj, int node, int parent) {
        parents[node] = parent;
        depths[node] = (node == parent) ? 0 : depths[parent] + 1;
        maxDepth = max(maxDepth, depths[node]);

        for(int next : adj[node]) {
            if(next != parent) {
                Dfs(adj, next, node);
            }
        }
    }

    void BuildTrans() {
        for(int step = 0; step < maxStep; step ++) {
            for(int node = 0; node < n; node ++) {
                if(step == 0) trans[node][0] = parents[node];
                else {
                    trans[node][step] = trans[trans[node][step - 1]][step - 1];
                }
            }
        }
    }   

public:
    BinaryLifting(vector<vector<int>> & adj, int root) {
        n = adj.size();
        parents.resize(n);
        depths.resize(n);

        Dfs(adj, root, root);

        while((1 << maxStep) <= maxDepth) maxStep ++;
        trans.resize(n, vector<int>(maxStep, -1));

        BuildTrans();
    }

    int GetAncestor(int node, int k) {
        if(depths[node] < k) return -1;

        for(int bit = maxStep - 1; bit >= 0; bit --) {
            if(k & (1LL << bit)) {
                node = trans[node][bit];
            }
        }

        return node;
    }
};
