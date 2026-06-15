1class Solution {
2public:
3    int orangesRotting(vector<vector<int>>& grid) {
4        int n = grid.size();
5        int m = grid[0].size();
6        vector<vector<int>> vis(n, vector<int>(m, 0));
7        queue < pair<pair<int, int>, int>> q;
8        for (int i = 0; i < n; i++) {
9            for (int j = 0; j < m; j++) {
10                if (grid[i][j] == 2) {
11                    q.push({{i, j}, 0});
12                    vis[i][j] = 1;
13                }
14            }
15        }
16        int minutes = 0;
17        while (!q.empty()) {
18            int row = q.front().first.first;
19            int col = q.front().first.second;
20            int min = q.front().second;
21            q.pop() ;
22            minutes = max(minutes, min);
23            int dr[4] = {-1, 1, 0, 0};
24            int dc[4] = {0, 0, -1, 1};
25            for (int i = 0; i < 4; i++) {
26                int nr = row + dr[i];
27                int nc = col + dc[i];
28                if (nc >= 0 && nr < n && nr >= 0 && nc < m && !vis[nr][nc] &&
29                    grid[nr][nc] == 1) {
30                    vis[nr][nc] = 1 ;
31                    q.push({{nr,nc},min + 1}) ;
32                }
33            }
34        }
35        for( int i = 0 ; i < n ; i++ ){
36            for( int j = 0 ; j < m ; j++ ){
37                if(!vis[i][j] && grid[i][j] == 1){
38                    return -1 ;
39                }
40            }
41        }
42        return minutes ;
43    }
44};