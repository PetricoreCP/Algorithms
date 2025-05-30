// Fast Fourier Transformation
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ldb = long double;
using cx = complex<ldb>;
 
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

const double PI = atan2(0, -1);

vector<cx> fft(vector<cx>& p) {
    int n = p.size();
    if (n == 1) {
        return p;
    }
    vector<cx> p_even(n / 2), p_odd(n / 2);
    for (int i = 0; i < n / 2; i ++) {
        p_even[i] = p[i * 2];
        p_odd[i] = p[i * 2 + 1];
    }
    vector<cx> even_val = fft(p_even);
    vector<cx> odd_val = fft(p_odd);
    vector<cx> p_val(n);
    for (int i = 0; i < n / 2; i ++) {
        cx tmp_val(cos(2 * PI * i / n), sin(2 * PI * i / n));
        p_val[i] = even_val[i] + tmp_val * odd_val[i];
        p_val[i + n / 2] = even_val[i] - tmp_val * odd_val[i];
    }
    return p_val;
}

vector<cx> ifft(vector<cx>& p_val) {
    int n = p_val.size();
    if (n == 1) {
        return p_val;
    }
    vector<cx> even_val(n / 2), odd_val(n / 2);
    for (int i = 0; i < n / 2; i ++) {
        cx tmp_val(cos(2 * PI * i / n), sin(2 * PI * i / n));
        even_val[i] = (p_val[i + n / 2] + p_val[i]) / (cx) 2;
        odd_val[i] = (p_val[i] - even_val[i]) / tmp_val;
    }
    vector<cx> p_even = ifft(even_val);
    vector<cx> p_odd = ifft(odd_val);
    vector<cx> p(n);
    for (int i = 0; i < n / 2; i ++) {
        p[i * 2] = p_even[i];
        p[i * 2 + 1] = p_odd[i];
    }
    return p;
}

vector<ll> FFT(vector<ll>& p, vector<ll>& q) {
    int n = 1;
    while (n < p.size() + q.size() - 1) {
        n <<= 1;
    }
    vector<cx> p_cx(n), q_cx(n);
    for (int i = 0; i < p.size(); i ++) {
        p_cx[i] = p[i];
    }
    for (int i = 0; i < q.size(); i ++) {
        q_cx[i] = q[i];
    }
    vector<cx> p_val = fft(p_cx);
    vector<cx> q_val = fft(q_cx);
    vector<cx> r_val(n);
    for (int i = 0; i < n; i ++) {
        r_val[i] = p_val[i] * q_val[i];
    }
    vector<cx> r_cx = ifft(r_val);
    vector<ll> r(n);
    for (int i = 0; i < n; i ++) {
        r[i] = round(r_cx[i].real());
    }
    return r;
}

int main() {
    fast_io
    int n; cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; i ++) {
        cin >> p[i];
    }
    int m; cin >> m;
    vector<ll> q(m);
    for (int i = 0; i < m; i ++) {
        cin >> q[i];
    }
    vector<ll> r = FFT(p, q);
    for (int i = 0; i < n + m - 1; i ++) {
        cout << r[i] << ' ';
    }
    return 0;
}
