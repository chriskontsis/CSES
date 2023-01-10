#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm> 
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    unordered_map<int, int> map;
    for(int i = 0; i < n; ++i) 
        cin >> a[i];


    for(int i = 0; i < n; i++) {
        if(map.find(x-a[i]) != map.end()) {
            cout << map[x-a[i]]+1 << " " << i+1 << '\n';
            return 0;
        }
        map[a[i]] = i;
    }

    cout << "IMPOSSIBLE" << '\n';
}
