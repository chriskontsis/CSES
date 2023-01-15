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
    
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    ll sumbefore = 0;
    for(int i = 0; i < n-1; i++)
        sumbefore+=a[i];

    if(a[n-1] > sumbefore) cout << a[n-1]*2 << '\n';
    else cout << sumbefore+a[n-1] << '\n';
}   
