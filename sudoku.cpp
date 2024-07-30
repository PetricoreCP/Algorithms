#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> solutions;

vector<string> grid = {
    "700304800",
    "080000005",
    "000070030",
    "600082009",
    "008605100",
    "400930002",
    "800020000",
    "005000020",
    "060507008"
};

bool check(char c, int i, int j) {
    for(int row = 0; row < 9; row ++) {
        if(row != i && grid[row][j] == c) return false;
    }
    for(int col = 0; col < 9; col ++) {
        if(col != j && grid[i][col] == c) return false;
    }
    int I = i / 3 * 3, J = j / 3 * 3;
    for(int row = I; row < I + 3; row ++) {
        for(int col = J; col < J + 3; col ++) {
            if(row != i && col != j && grid[row][col] == c) return false;
        }
    }
    return true;
}

void sudoku() {
    for(int i = 0; i < 9; i ++) {
        for(int j = 0; j < 9; j ++) {
            if(grid[i][j] == '0') {
                for(char c = '1'; c <= '9'; c ++) {
                    if(check(c, i, j)) {
                        grid[i][j] = c;
                        sudoku();
                        grid[i][j] = '0';
                    }
                }
            }
            if(grid[i][j] == '0') return;
        }
    }
    solutions.push_back(grid);
}

void solve() {
    sudoku();
    cout << "Valid Solutions: " << solutions.size() << ".\n\n";
    for(auto &s : solutions) {
        for(int i = 0; i < 9; i ++) {
            cout << s[i] << '\n';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int tc = 1;
    //cin >> tc;
    while(tc --) solve();
    return 0;
}
