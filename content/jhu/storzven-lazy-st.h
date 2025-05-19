/**
 * Author: Storzven (Steven) Tan
 * Date: 
 * License: 
 * Description: Storzven Tan's Lazy Segment Tree
 * Time:
 * Status: 
 */
#pragma once
struct LazySegTree {
    vector<int> t, lazy;
    LazySegTree(int n) : t(4 * n), lazy(4 * n) {}
    void push(int v) {
        if (lazy[v] != 0) {
            lazy[v * 2] += lazy[v]; t[v * 2] += lazy[v];
            lazy[v * 2 + 1] += lazy[v]; t[v * 2 + 1] += lazy[v];
            lazy[v] = 0;
        }
    }
    void update(int v, int l, int r, int ql, int qr, int add) {
        if (qr < l || ql > r) return;
        else if (ql <= l && qr >= r) {
            t[v] += add, lazy[v] += add;
        } else {
            push(v);
            int m = (l + r) / 2;
            update(v * 2, l, m, ql, qr, add);
            update(v * 2 + 1, m + 1, r, ql, qr, add);
            t[v] = max(t[v * 2], t[v * 2 + 1]);
        }
    }
    int query(int v, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return INT_MIN;
        else if (ql <= l && qr >= r) return t[v];
        else {
            push(v);
            int m = (l + r) / 2;
            return max(query(v * 2, l, m, ql, qr), query(v * 2 + 1, m + 1, r, ql, qr));
        }
    }
};