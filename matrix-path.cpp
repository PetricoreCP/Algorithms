#include <bits/stdc++.h>
using namespace std;
 
using i32 = int32_t;
using i64 = int64_t;

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

vector<vector<i64>> dijkstra(i32 n, i32 m, vector<vector<i64>> &matrix, pair<i32, i32> &start, vector<vector<pair<i32, i32>>> &path) {
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
                path[next.first][next.second] = node;
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
    i32 n, m, q;
    // Matrix Dimensions: n, m
    // Q Walls (xi, yi) 0-indexed coordinates each
    cin >> n >> m >> q;
    vector<vector<i64>> matrix(n, vector<i64>(m, 1ll));
    vector<vector<pair<i32, i32>>> path(n, vector<pair<i32, i32>>(m, {-1, -1}));
    path[0][0] = make_pair(0, 0);
    pair<i32, i32> start = make_pair(0, 0);
    for(i32 i = 0; i < q; i ++) {
        i32 x, y;
        cin >> x >> y;
        matrix[x][y] = INF64;
    }
    vector<vector<i64>> d = dijkstra(n, m, matrix, start, path);
    // Get minimum cost for each state, -1 is not reachable 
    for(i32 i = 0; i < n; i ++) {
        for(i32 j = 0; j < m; j ++) {
            if(d[i][j] < INF64) {
                cout << d[i][j] << ' ';
            }
            else {
                cout << -1 << ' ';
            }
        }
        cout << '\n';
    }
    // Retrieve path[n - 1][m - 1];
    vector<pair<i32, i32>> retrieve;
    retrieve.push_back(make_pair(n - 1, m - 1));
    while(path[n - 1][m - 1] != make_pair(0, 0)) {
        retrieve.push_back(path[n - 1][m - 1]);
        path[n - 1][m - 1] = path[path[n - 1][m - 1].first][path[n - 1][m - 1].second];
    }
    retrieve.push_back(make_pair(0, 0));
    reverse(retrieve.begin(), retrieve.end());
    for(auto &k : retrieve) {
        cout << "(" << k.first << ", " << k.second << ") ";
    }
    return 0;
}
