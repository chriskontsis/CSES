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
    int n;
    cin >> n;
    vector<pair<ll,ll> > a(n);
    for(int i = 0; i < n; i++) 
        cin >>  a[i].first >> a[i].second;

    sort(a.begin(), a.end());

   ll second = 0;
   ll ans = 0;
   for(int i = 0; i < n; i++) {
        int start = a[i].first;
        int end = a[i].second;

        second+= start;
        ans += (end - second);
   }
   cout << ans << '\n';
}   
