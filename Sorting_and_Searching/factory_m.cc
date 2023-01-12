#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm> 
#include <unordered_map>
#include <climits>
#include <unordered_set>
#include <queue>

using ll = long long int;
using namespace std;

const int mxN = 2e5*5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,t; 
    cin >> n >> t;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    ll lo = 0, hi = 1e18;
    ll ans = 0;

    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll sum = 0;
        for(int i =0; i < n; i++) {
            sum+=(mid/a[i]);
            if(sum >= t) break;
        }

        if(sum >= t) {
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;

    }
    cout << ans << '\n';
}   
