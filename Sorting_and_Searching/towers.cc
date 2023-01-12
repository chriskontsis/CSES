#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm> 
#include <unordered_map>
#include <climits>
#include <unordered_set>

using ll = long long int;
using namespace std;

const int mxN = 2e5*5;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    multiset<int> set;

    for(int i = 0; i < n; i++) {
        auto it = set.upper_bound(a[i]);

        if(it == set.end()) {
            ++ans;
            set.insert(a[i]);
        }
        else {
            set.erase(set.lower_bound(*it));
            set.insert(a[i]);
        }
    }
    cout << ans << '\n';
}   
