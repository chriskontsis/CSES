#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm> 

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,a,b;
    cin >> n;
    map<int,int> map;

    for(int i = 0; i < n; ++i) {
        cin >> a >> b;
        ++map[a];
        --map[b];
    }
    int customers = 0;
    int maxcustomers = 0;
    for(auto entry : map) {
        customers+=entry.second;
        maxcustomers = max(customers, maxcustomers);
    }
    cout << maxcustomers << '\n';
}
