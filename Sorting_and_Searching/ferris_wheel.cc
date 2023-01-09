#include <iostream> 
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int n, x;
    int ans = 0;
    cin >> n >> x;
    vector<int> a(n);

    for(int i = 0; i < n; i++) 
        cin >> a[i];

    sort(a.begin(), a.end());
    int lo = 0, hi = a.size()-1;
    unordered_set<int> set;

    while(lo < hi) {
        if(a[lo] + a[hi] > x) 
            --hi;
        else {
            ++ans;
            set.insert(lo);
            set.insert(hi);
            ++lo, --hi;
        }
    }

    for(int i = 0; i < n; i++) {
        if(!set.count(i)) 
            ++ans;
    }

    
    cout << ans << '\n';
}