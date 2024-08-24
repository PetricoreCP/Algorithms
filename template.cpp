/*
*  _____     _        _              
* |  __ \   | |      (_)
* | |__) |__| |_ _ __ _  ___ ____  _ __ ___
* |  ___/ _ \ __| '__| |/ __/    \| '__/ _ \
* | |  |  __/ |_| |  | | (__  ()  | | |  __/
* |_|   \___|\__|_|  |_|\___\____/|_|  \___|
*
*/

#include <bits/stdc++.h>
using namespace std;
    
void testCase() {}

int main() {
    auto start = chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int tc = 1;
    //cin >> tc;
    while (tc --) {
        testCase();
    }
    auto stop = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cerr << "\nTime elapsed: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
