#include <iostream>
#include <vector>
#include <stdio.h>
#include<climits>
#include <thread>

using namespace std;
typedef long long ll;
const int mxN = 2e5;

int N, Q, l, r, t;
ll seg[4*mxN];

void build(ll a[], int v, int tl, int tr) {
    if(tl == tr) {
        seg[v] = a[tl];
    }
    else {
        int tm = (tl+tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        seg[v] = seg[v*2]+seg[v*2+1];
    }
}

long long sum(int v, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(l == tl && r == tr) {
        return seg[v];
    }
    else {
        int tm = (tl+tr) / 2;
        return sum(v*2, tl, tm, l, min(r,tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
}

void update(int v, int tl, int tr, int pos, int newval) {
    if(tl == tr) {
        seg[v] = newval;
    }
    else {
        int tm = (tl+tr) / 2;
        if(pos <= tm) 
            update(v*2, tl, tm, pos, newval);
        else 
            update(v*2+1, tm+1, tr, pos, newval);
        seg[v] = seg[v*2] + seg[v*2+1];
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin >> N >> Q;
    ll a[4*mxN];
    for(int i = 0; i < N; i++) 
        cin >> a[i];
    build(a, 1, 0, N-1);    

    for(int i = 0; i < Q; i++) {
        cin >> t >> l >> r;
        if(t == 2) {
            cout << sum(1, 0, N-1, l-1, r-1) << '\n';
        }
        else update(1, 0, N-1, l-1, r);
    }

}