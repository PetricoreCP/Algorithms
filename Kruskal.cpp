class Dsu {
private:
    vector<int> p, sz;
public:
    Dsu(int n) {
        p.resize(n);
        sz.resize(n, 1);
        for(int i = 0; i < n; i ++) {
            p[i] = i;
        }
    }    
    int find(int u) {
        int node = u;
        while(p[node] != node) {
            node = p[node];
        }
        while(p[u] != u) {
            int tmp = p[u];
            p[u] = node;
            u = tmp;
        }
        return node;
    }
    bool join(int u, int v) {
        int a = find(u), b = find(v);   
        if(a == b) return false;
        if(sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        p[b] = a;
        return true;
    }
};

long long Kruskal(vector<tuple<long long, int, int>> & edg, int n) {
    sort(edg.begin(), edg.end());
    Dsu dsu(n);
    long long res = 0;
    for (auto & e : edg) {
        long long w = get<0>(e);
        int u = get<1>(e);
        int v = get<2>(e);
        if (dsu.join(u, v)) {
            res += w;
        }
    }
    return res;
}
