#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm> 
#include <unordered_map>
#include <climits>

using ll = long long int;
using namespace std;

const int mxN = 2e5*5;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++) 
        cin >> a[i];

    sort(a.begin(), a.end());
    ll ans = 1;

    for(int i = 0; i < n && a[i] <= ans; ++i) {
        ans+=a[i];
    }   

    cout << ans << '\n';
}
