#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm> 
#include <unordered_map>
#include <climits>
#include <unordered_set>

using ll = long long int;
using namespace std;

const int mxN = 2e5*5;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; 
    cin >> n;


    for(int i = 2; i <= n; i+=2) 
        cout << i << " ";
    for(int i = 1; i <= n; i+=4) 
        cout << i << " ";
    for(int i = 3; i <=n; i+=4) 
        cout << i << " ";


}   
