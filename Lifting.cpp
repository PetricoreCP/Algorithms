#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

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
        for(int node = 0; node < n; node ++) {
            trans[node][0] = parents[node];
            for(int step = 1; step < maxStep; step ++) {
                trans[node][step] = trans[trans[node][step - 1]][step - 1];
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
        trans.resize(n, vector<int>(maxStep));

        BuildTrans();
    }

    int GetAncestor(int node, int k) {
        if(depths[node] < k) return -1;

        for(int bit = 0; bit < maxStep; bit ++) {
            if((k >> bit) & 1) {
                node = trans[node][bit];
            }
        }

        return node;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int tc = 1;
    //cin >> tc;

    while(tc--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n);
        for(int i = 0; i < m; i ++) {
            int u, v;
            cin >> u >> v;
            u --; v --;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        BinaryLifting tree(adj, 0);

        int q;
        cin >> q;

        for(int i = 0; i < q; i ++) {
            int u, k;
            cin >> u >> k;
            u --;
            int v = tree.GetAncestor(u, k);
            cout << ((v == -1) ? v : v + 1) << '\n';
        }
    }

    return 0;
}
