#include <iostream>
using namespace std;


int main(){
    	int t, a, b, x;
    	std::cin >> t;
    	while ( t-- ) {
    		cin >> a >> b;
            if(a < b) swap(a,b);
            if(a > 2*b) cout << "NO" << '\n';
            else {
                if((a+b) % 3 == 0 ) cout << "YES" << '\n';
                else cout << "NO" << '\n';
            }
    	}
    	return 0;
    }