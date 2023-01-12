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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

   

    int n; 
    cin >> n;
    vector<pair<pair<int,int>, int> >p(n); 
    for(int i = 0; i < n; i++) {
        cin >> p[i].first.first >> p[i].first.second;
        p[i].second = i;
    }
    
    sort(p.begin(), p.end());
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    vector<int> order(n);
    int rooms = 0, curroom = 0;

    for(int i = 0; i < n; i++) {
        if(pq.empty()) {
            ++curroom;
            pq.push({p[i].first.second, curroom});
            order[p[i].second] = curroom;
        }
        else {
            auto [endtime, roomnum] = pq.top();
            if(endtime < p[i].first.first) {
                pq.pop();
                pq.push({p[i].first.second, roomnum});
                order[p[i].second] = roomnum;
            }
            else {
                curroom++;
                pq.push({p[i].first.second, curroom});
                order[p[i].second] = curroom;
            }
        }
        rooms = max(rooms, (int)pq.size());
    }

    cout << rooms << '\n';
    for(int i = 0; i < n; i++)
        cout << order[i] << " ";
}   
