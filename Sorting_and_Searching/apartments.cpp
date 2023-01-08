#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n, k;
    cin >> n >> m >> k;
    vector<int> prices;
    vector<int> size;
    for(int i =1; i <= n; i++) {
        int a;
        cin >> a;
        prices.push_back(a);
    }

    for(int i = 1; i <= m; i++) {
        int a; 
        cin >> a;
        size.push_back(a);
    }

    sort(prices.begin(), prices.end());
    sort(size.begin(),  size.end());
    int ans = 0;
    for(int i = 0, j = 0; i < n; ++i) {
        while(j < m && size[j] < prices[i]-k) {
            j++;
        }
        if(j < m && size[j] <= prices[i] + k) {
            ++ans, ++j;
        }
    }
    cout << ans << endl;
}