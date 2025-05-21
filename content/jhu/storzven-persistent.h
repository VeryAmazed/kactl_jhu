/**
 * Author: Storzven (Steven) Tan
 * Date: 
 * License: 
 * Description:
 * Time:
 * Status: 
 */
#pragma once
const int MAXN = 100005, MAXV = MAXN * 60;
ll vals[MAXV]; // initialize with default val
int ls[MAXV], rs[MAXV]; // initialize with 0s
int ind = 1; // 0 is sentinel node
int update(int v, ll l, ll r, ll i, ll x) { 
    int t = ind++;
    if (l == r) vals[t] = x;
    else {
        ls[t] = ls[v]; rs[t] = rs[v];
        ll m = (l + r) / 2;
        if (i <= m) ls[t] = update(ls[t], l, m, i, x);
        else rs[t] = update(rs[t], m + 1, r, i, x);
        vals[t] = vals[ls[t]] + vals[rs[t]];
    }
    return t;
}
ll query(int v, ll l, ll r, ll ql, ll qr) {
    if (v == 0 || qr < l || ql > r) return 0;
    else if (ql <= l && qr >= r) return vals[v];
    else {
        ll m = (l + r) / 2;
        return query(ls[v], l, m, ql, qr) + query(rs[v], m + 1, r, ql, qr);
    }
}//min i s.t. v1.query(0, i) - v2.query(0, i) >= k
int walk(int v1, int v2, ll l, ll r, ll k) {
    if (l == r) return l;
    ll m = (l + r) / 2;
    ll sum = vals[ls[v1]] - vals[ls[v2]];
    if(sum >= k) return walk(ls[v1], ls[v2], l, m, k);
    else return walk(rs[v1], rs[v2], m + 1, r, k - sum);
}