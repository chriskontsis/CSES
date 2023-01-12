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
    vector<int> a(n), b(n);
    int ans = 0;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    unordered_map<int,int> map;


    for(int i = 0, j=0; i < n; i++) {
       j = max(map[a[i]], j);

       ans = max(ans, i-j+1);
       map[a[i]] = i+1;
    }

    cout << ans << '\n';
}   
