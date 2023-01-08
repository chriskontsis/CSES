#include <bits/stdc++.h> 
#include <iostream> 
#include <vector>
using namespace std;


int main() {
    string s;
    cin >> s;
    int ans = 1;
    int prevsum = 1;
    char prev;

    for(int i = 0; i < s.size(); ++i) {
        if(i == 0) {
            prev = s[i];
            continue;
        }
        else if(prev == s[i]) {
            prevsum++;
            ans = max(ans,prevsum);
        }
        else {
            prevsum = 1;
        }
        prev = s[i];
    }
    cout << ans << endl;
}