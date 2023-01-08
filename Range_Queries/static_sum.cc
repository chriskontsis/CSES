#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5;

int N, Q, a, b;
ll x[maxN+1];

int main(){
    cin >> N >> Q;
    for(int i = 1; i <= N; i++){
        cin >> x[i];
        x[i] += x[i-1];
    }
    for(int q = 0; q < Q; q++){
        cin >> a >> b;
        cout << x[b] - x[a-1] << '\n';
    }
}