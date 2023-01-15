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
    cin >> n >> amount;;
    int mod = 1e9+7;

    vector<ll> coins(n);
    vector<ll> minWaysToAmount(amount+1,INT_MAX);
    minWaysToAmount[0]=0;

    for(int i = 0; i < n; i++)
        cin >> coins[i];

    for(int i = 1; i <= amount; i++) {
        for(int c = 0; c < n; c++) {
            if(coins[c] <= i) {
                minWaysToAmount[i] = min(1+minWaysToAmount[i-coins[c]], minWaysToAmount[i]);
            }
        }
    }
    
    if(minWaysToAmount[amount] > amount) cout << -1 << '\n';
    else cout << minWaysToAmount[amount] << '\n';
    
}   
