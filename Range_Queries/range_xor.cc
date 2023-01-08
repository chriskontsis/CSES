#include <iostream>
#include <vector>
#include <stdio.h>
#include<climits>
#include <thread>

using namespace std;
typedef long long ll;
const int mxN = 2e5;

int N, Q, l, r;
ll a[mxN+1], prefix[mxN+1];

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for(int i = 1; i<=N; i++) {
        cin >> a[i];
    }

    prefix[1] = a[1];
    for(int i = 2; i<=N; i++) {
        prefix[i] = prefix[i-1] ^ a[i];
    }

    while(Q--) {
        cin >> l >> r;
        cout << (prefix[r] ^ prefix[l-1]) << '\n';
    }

}