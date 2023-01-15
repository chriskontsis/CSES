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
    int n;
    cin >> n;
    int mod = 1e9+7;
    vector<int> dp(n+1,0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j<=6; j++) {
            if(i - j >= 0) {
                (dp[i] += dp[i-j]) %= mod;
            }
        }
    }

    cout << dp[n] << '\n';
}   
