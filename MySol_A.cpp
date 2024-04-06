#include <bits/stdc++.h>
using namespace std;
// Using binary exponentiation
  // inv(a) = a^(MOD-2)
  // works only when MOD is prime
  // see Fermat's little theorem
int64_t expo(int64_t a, int64_t b, int64_t MOD) {      // a^b % MOD
    int64_t res = 1;
    a %= MOD;
    while(b > 0) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
// Using Extended Euclidean algorithm
  // inv(a, MOD) = -(MOD/a) * inv(MOD, a) % MOD
  // Proof := https://cp-algorithms.com/algebra/module-inverse.html#toc-tgt-4
  // works when a and MOD are coprime
int64_t inv(int64_t a, int64_t m) {        // inv(a, MOD)
    a %= m;
    if(a == 1) return 1;
    return m - inv(m%a, m) * (m / a);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int Q; int64_t MOD;
    while(cin >> MOD >> Q, MOD) {
        while(Q--) {
            int64_t a, b, ans; char op;
            cin >> a >> op >> b;
            a %= MOD;
            b %= MOD;
            bool bad = op == '/' and gcd((int64_t)b, MOD) != 1;
            if(op == '+')
                ans = (a + b) % MOD;
            else if(op == '-')
                ans = ((a - b) % MOD + MOD) % MOD;
            else if(op == '*')
                ans = a * b % MOD;
            else if(!bad)
                ans = a * inv(b, MOD) % MOD;
            if(bad) cout << -1 << '\n';
            else cout << ans << '\n';
        }
    }
}
