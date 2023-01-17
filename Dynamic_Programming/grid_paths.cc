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
    vector<vector<char> >grid(n, vector<char>(n));
    vector<vector<int> >dp(n, vector<int>(n,0));
    int mod = 1e9+7;
 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    if(grid[0][0] == '*') {cout << 0; return 0;}
    dp[0][0] = 1;
    bool isBlocked = false;

    for(int i = 1; i < n; i++) {
        if(grid[i][0] == '*' || isBlocked) {
            dp[i][0] = 0; 
            isBlocked = true;
        }
        else dp[i][0] = 1; 
    }
    isBlocked = false;
    for(int j = 1; j < n; j++) {
        if(grid[0][j] == '*' || isBlocked) {
            dp[0][j] = 0; 
            isBlocked = true;
        }
        else dp[0][j] = 1; 
    }
 
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
 
            if(grid[i][j] == '*') dp[i][j] = 0;
            else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
            }
        }
    }
    cout << dp[n-1][n-1] % mod << '\n';
}   