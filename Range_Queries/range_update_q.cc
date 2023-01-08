#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
const int mxN = 2e5;
ll seg[4*mxN];
int N, Q, t;


void build(int arr[], int v, int tl, int tr) {
    if(tl == tr) 
        seg[v] = arr[tl];
    else {
        int tm = (tl+tr) / 2;
        build(arr, v*2, tl, tm);
        build(arr, v*2+1, tm+1, tr);
        seg[v] = 0;
    }
}
void update(int v, int tl, int tr, int l, int r, int add) {
    if(l > r) return;
    if(tl == l && tr == r) {
        seg[v] +=add;
    }
    else {
        int tm = (tl+tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}

ll qry(int v, int tl, int tr, int pos) {
    if(tl == tr) 
        return seg[v];
    int tm = (tl+tr) / 2;
    if(pos <= tm)  
        return seg[v] + qry(v*2, tl, tm, pos);
    else    
        return seg[v] + qry(v*2+1, tm+1, tr, pos);
}

int main() {
    cin >> N >> Q;
    int arr[4*mxN];

    for(int i = 0; i < N; i++) 
        cin >> arr[i];
    
    build(arr, 1, 0, N-1);
   
    while(Q--) {
        cin >> t;
        if(t == 1) {
            int a,b,u;
            cin >> a >> b >> u;
            update(1, 0, N-1, a-1, b-1, u);
        }
        else {
            int k;
            cin >> k;
            cout << qry(1, 0, N-1, k-1) << '\n';
        }
    }
}