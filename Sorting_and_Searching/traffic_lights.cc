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
    cout.tie(0);

    int street_len, light_num;
    cin >> street_len >> light_num;

    set<int> lights{0, street_len};
    multiset<int> dist{street_len};

    for(int i = 0; i < light_num; i++) {
        int pos;
        cin >> pos;

        auto it1 = lights.upper_bound(pos);
        auto it2 = it1;
        --it2;
        
        dist.erase(dist.find(*it1 - *it2));
        dist.insert(pos - *it2);
        dist.insert(*it1 - pos);
        lights.insert(pos);

        auto ans = dist.end();
        --ans;
        cout << *ans << " ";
    }
}   
