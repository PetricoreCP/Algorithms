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

struct Dsu {
    vector<int> parent, sz;
    Dsu(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) {
        while (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    bool join(int u, int v) {
        u = find(u);
        v = find(v);   
        if (u == v) {
            return false;
        }
        if (sz[u] < sz[v]) {
            swap(u, v);
        }
        sz[u] += sz[v];
        parent[v] = u;
        return true;
    }
    bool same(int u, int v) {
        return find(u) == find(v);
    }
};
