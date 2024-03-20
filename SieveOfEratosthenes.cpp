#include <iostream>
#include <vector>

template <typename T>
std::vector <bool> Sieve(T n) {
    std::vector <bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for(T p = 2; p * p <= n; p ++) {
        if(prime[p]) {
            for(T m = p * p; m <= n; m += p) {
                prime[m] = false;
            }
        }
    }

    return prime;
}

void Main() {
    int n;
    std::cin >> n;

    std::vector <bool> prime = Sieve(n);

    for(int p = 1; p <= n; p ++) {
        if(prime[p]) {
            std::cout << p << ' ';
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", output);
    
    int t = 1;
    //std::cin >> t;

    while(t--) {
        Main();
    }

    return 0;
}
