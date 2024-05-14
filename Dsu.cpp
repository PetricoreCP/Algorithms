class Dsu {
private:
    vector<int> parents, sz;

public:
    Dsu(int n) {
        parents.resize(n);
        sz.resize(n, 1);
        for(int i = 0; i < n; i ++) {
            parents[i] = i;
        }
    }    

    int find(int u) {
        int node = u;
        while(parents[node] != node) {
            node = parents[node];
        }
        while(parents[u] != u) {
            int tmp = parents[u];
            parents[u] = node;
            u = tmp;
        }
        return node;
    }

    bool join(int u, int v) {
        int a = find(u), b = find(v);   
        if(a == b) return false;
        if(sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        parents[b] = a;
        return true;
    }
};
