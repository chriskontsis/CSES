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


    ll currmax = a[0], sofar = a[0];
    for(int i = 1; i < n; ++i) {
        currmax = max((ll) a[i], a[i]+currmax);
        sofar = max(currmax, sofar);
    }

    cout << sofar << '\n';
}
