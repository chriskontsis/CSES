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
    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) 
        cin >> a[i], a[i]--;

    for(int i = 0; i < n; ++i) 
        b[a[i]] = i;

    int ans = 1;
    for(int i = 1; i <n; i++) 
        ans+=b[i] < b[i-1];

    cout << ans << '\n';
}   
