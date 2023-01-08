#include <iostream>
#include <vector>
#include <stdio.h>
#include<climits>
#include <thread>

using namespace std;
typedef long long ll;
const int mxN = 2e5;

int N, Q, l, r;
ll seg[4*mxN];

void build(int a[], int v, int tl, int tr) {
    if(tl == tr) {
        seg[v] = a[tl];
    }
    else {
        int tm = (tl+tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        seg[v] = min(seg[v*2], seg[v*2+1]);
    }
}

int getMin(int v, int tl, int tr, int l, int r) {
    if(l > r) return INT_MAX;
    if(l == tl && r == tr) {
        return seg[v];
    }
    int tm = (tl+tr) / 2;
    return min(getMin(v*2, tl, tm, l, min(r, tm)), 
                getMin(v*2+1, tm+1, tr, max(l,tm+1), r));
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin >> N >> Q;
    int a[4*mxN];
    for(int i = 0; i < N; i++) 
        cin >> a[i];
    build(a, 1, 0, N-1);

    for(int i = 0; i < Q; i++) {
        cin >> l >> r;
        cout << getMin(1, 0, N-1, l-1, r-1) << '\n';
    }
}