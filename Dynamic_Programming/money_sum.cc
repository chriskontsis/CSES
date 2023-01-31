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
    vector<int> coins(n);
    for(int i = 0; i < n; i++)
        cin >> coins[i];

    int mxSum = n*1000;
    vector<vector<bool> > dp(n+1, vector<bool>(mxSum+1, false));
    dp[0][0] = true;

    for(int i = 1; i <= n; i++) {
        for(int sum = 0; sum<=mxSum; sum++) {
            dp[i][sum] = dp[i-1][sum];
            if(sum - coins[i-1] >= 0 && dp[i-1][sum-coins[i-1]]) 
                dp[i][sum] = true;
        }
    }

    vector<int> ans;
    for(int i = 1; i <= mxSum;i++) {
        if(dp[n][i]) ans.push_back(i);
    }
    
    cout << ans.size() << '\n';
    for(auto x : ans) 
        cout << x << " ";





    /*
    
    1,2,3,4,5,6,7,8,9,10,11,12,13
   4 
   2 
   5
   2 
    */
}
