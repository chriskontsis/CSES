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
    

    int books, price;
    cin >> books >> price;
    vector<int> prices(books), pages(books);
    vector<int> dp(price+1, 0);
    for(int& v: prices) cin >> v;
    for(int& v: pages) cin >> v;

    for(int i = 0; i < books; i++) {
        for(int j = price; j>=prices[i]; j--) {
                dp[j] = max(dp[j], dp[j-prices[i]] + pages[i]);
        }
    }
    cout << dp[price];
}