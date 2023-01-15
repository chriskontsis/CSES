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
    /*
    dp[x] = number of ways to make sum x using numbers from 1 to 6

    */
    int n, amount;
    int mod = 1e9+7;
    cin >> n >> amount;;
    vector<ll> dp(amount+1,0);
    vector<ll> coins(n);


    for(int i = 0; i < n; i++)
        cin >> coins[i];

    dp[0] = 1;
    
    for(int c : coins) {
        for(int i = 0; i <= amount; i++) {
            if(i - c >= 0) {
                dp[i] += dp[i-c];
                dp[i] %= mod;
        }
    }
    
    cout << dp[amount] << '\n';
}   
