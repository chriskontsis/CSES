#include <iostream> 
#include <vector>
using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr[i] = a;
    }
    long long ans = 0;
    for(int i = 1; i < n; ++i) {
        if(arr[i] < arr[i-1]) {
            ans += abs(arr[i] - arr[i-1]);
            arr[i] = arr[i-1];
        }
        
    }
    cout << ans << endl;
}