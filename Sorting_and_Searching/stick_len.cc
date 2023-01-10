#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm> 
#include <unordered_map>
#include <climits>

using ll = long long int;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++) 
        cin >> a[i];

    sort(a.begin(), a.end());

    ll ans = 0;
    int stick = a[n/2];
    for(int i = 0; i < n; i++) {
        ans+= abs(stick-a[i]);
    }
    cout << ans << '\n';
}
