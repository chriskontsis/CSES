#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm> 

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n;
    vector<pair<int,int> > movies(n);
    for(int i = 0; i < n; ++i) {
        cin >> movies[i].second >> movies[i].first;
    }
    sort(movies.begin(), movies.end());

    int ans = 0;
    int endLast = -1;

    for(int i = 0; i < n; i++) {
        if(movies[i].second >= endLast) {
            ++ans;
            endLast = movies[i].first;
        }
    }
    cout << ans << '\n';
}
