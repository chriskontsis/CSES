#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm> 
#include <unordered_map>
#include <climits>
#include <queue>

using ll = long long int;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));
    int ans = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> map[i][j];

    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    queue<pair<int,int>>q;

    auto inGrid = [&](int nx, int ny) -> bool{
        return nx >= 0 && ny >= 0 && nx < n && ny < m;
    };
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == '.') {
                ++ans;
                q.push({i,j});
                map[i][j] = '#';

                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int k = 0; k < 4; k++) {
                        int nx = x + dirs[k][0];
                        int ny = y+ dirs[k][1];

                        if(inGrid(nx,ny) && map[nx][ny] == '.') {
                            map[nx][ny] = '#';
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
    }

    cout << ans;
}
