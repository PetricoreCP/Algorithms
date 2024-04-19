#include <iostream>
#include <vector>

using namespace std;

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
        if(sz[a] < sz[b]) std::swap(a, b);
        sz[a] += sz[b];
        p[b] = a;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", output);
    int tc = 1;
    //cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        Dsu dsu(n);
    }
    return 0;
}
