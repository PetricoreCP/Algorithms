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

long long Kruskal(vector<tuple<long long, int, int>> & edg, int n) {
    long long res = 0;
    sort(edg.begin(), edg.end());
    Dsu dsu(n);
    
    for (tuple<long long, int, int> & e : edg) {
        long long w = get<0>(e);
        int u = get<1>(e);
        int v = get<2>(e);

        if (dsu.join(u, v)) {
            res += w;
        }
    }

    return res;
}
