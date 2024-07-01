#include <bits/stdc++.h>
using namespace std;
 
using i32 = int32_t;
using i64 = int64_t;

/*
TO DO: PATH RETRIEVE
*/

const i64 INF64 = 1e18;

vector<pair<pair<i32, i32>, i64>> get_candidates(i32 n, i32 m, vector<vector<i64>> &matrix, pair<i32, i32> &p) {
    vector<pair<pair<i32, i32>, i64>> cnd; 
    i32 x = p.first, y = p.second;
    if(x > 0) {
        cnd.push_back(make_pair(make_pair(x - 1, y), matrix[x - 1][y]));
    }
    if(y > 0) {
        cnd.push_back(make_pair(make_pair(x, y - 1), matrix[x][y - 1]));
    }
    if(x < n - 1) {
        cnd.push_back(make_pair(make_pair(x + 1, y), matrix[x + 1][y]));
    }
    if(y < m - 1) {
        cnd.push_back(make_pair(make_pair(x, y + 1), matrix[x][y + 1]));
    }
    return cnd; 
}

vector<vector<i64>> dijkstra(i32 n, i32 m, vector<vector<i64>> &matrix, pair<i32, i32> &start) {
    vector<vector<i64>> cost(n, vector<i64>(m, INF64));
    cost[start.first][start.second] = 0;
    priority_queue<pair<i64, pair<i32, i32>>, vector<pair<i64, pair<i32, i32>>>, greater<pair<i64, pair<i32, i32>>>> pq;
    pq.push(make_pair(0, start));
    while(!pq.empty()) {
        pair<i64, pair<i32, i32>> p = pq.top();
        pq.pop();
        i64 c = p.first;
        pair<i32, i32> node = p.second;
        if(c > cost[node.first][node.second]) continue;
        vector<pair<pair<i32, i32>, i64>> cnd = get_candidates(n, m, matrix, node);
        for(auto &q : cnd) {
            pair<i32, i32> next = q.first;
            i64 w = q.second;
            if(c + w < cost[next.first][next.second]) {
                cost[next.first][next.second] = c + w;
                pq.push(make_pair(cost[next.first][next.second], next));
            }
        }
    }
    return cost;
}
 
i32 main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Matrix dimensions: n, m
    // Walls: q + 0-indexed coordinates
    i32 n, m, q;
    cin >> n >> m >> q;
    vector<vector<i64>> matrix(n, vector<i64>(m, 1ll));
    pair<i32, i32> start = {0, 0};
    for(i32 i = 0; i < q; i ++) {
        i32 x, y;
        cin >> x >> y;
        matrix[x][y] = INF64;
    }
    vector<vector<i64>> d = dijkstra(n, m, matrix, start);
    for(i32 i = 0; i < n; i ++) {
        for(i32 j = 0; j < m; j ++) {
            if(d[i][j] < INF64) {
                cout << 1 << ' ';
            }
            else {
                cout << 0 << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
