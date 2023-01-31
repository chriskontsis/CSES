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
    
    int n,m;
    cin >> n;
    vector<int> x(n);

    for(int i = 0; i <n; i++)
        cin >> x[i];

    vector<int> dp(n, 1);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(x[i] > x[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';
}
