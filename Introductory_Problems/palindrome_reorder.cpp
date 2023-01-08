#include <iostream>
#include <unordered_map> 
#include <bits/stdc++.h>        
using namespace std;

int main() {
    string n;
    cin >> n;

    unordered_map<char, int> map;

    for(char c : n) map[c]++;
    int odds = 0;
    char o;
    string ans;
    for(auto it : map) {
        if(it.second  % 2 == 1) {
            ++odds;
            if(odds > 1) {
                cout << "NO SOLUTION" << '\n';
                return 0;
            }
            o = it.first;
        } 
    }           

    for(auto it : map) {
        if(it.first != o) {
            ans=string(it.second/2, it.first) + ans;
        }
    }

    string temp = ans;
    
    int oddfreq = map[o];
    ans += string(oddfreq, o);
    reverse(temp.begin(), temp.end());
    ans+=temp;
    cout << ans << endl;

}