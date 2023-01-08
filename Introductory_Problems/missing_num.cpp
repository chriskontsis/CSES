#include <bits/stdc++.h> 
#include <iostream> 
#include <vector>
using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<int> vec(n+1,0);
    for(int i = 1; i < n; ++i) {
        int a; 
        cin >> a; 
        vec[a] = a;
    }

    for(int i = 1; i <= n; i++) {
        if(vec[i] == 0) cout << i << endl;
    }
}