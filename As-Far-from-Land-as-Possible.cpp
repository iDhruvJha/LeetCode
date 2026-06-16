1class Solution {
2public:
3    int maxDistance(vector<vector<int>>& grid) {
4        int n = grid.size();
5        int m = grid[0].size();
6        vector<vector<int>> vis(n, vector<int>(m, 0));
7        queue<pair<pair<int, int>, int>> q;
8        for (int i = 0; i < n; i++) {
9            for (int j = 0; j < m; j++) {
10                if (grid[i][j] == 1) {
11                    q.push({{i, j}, 0});
12                    vis[i][j] = 1;
13                }
14            }
15        }
16        if(q.empty()) return -1 ;
17        int delrow[] = {0, 0, 1, -1};
18        int delcol[] = {1, -1, 0, 0};
19        int ans = 0 ;
20        while (!q.empty()) {
21            int row = q.front().first.first;
22            int col = q.front().first.second;
23            int dist = q.front().second;
24            q.pop();
25            ans = max(ans,dist) ;
26            for (int i = 0; i < 4; i++) {
27                int nrow = row + delrow[i];
28                int ncol = col + delcol[i];
29                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
30                       !vis[nrow][ncol] && grid[nrow][ncol] == 0) {
31                    vis[nrow][ncol] = 1;
32                    q.push({{nrow, ncol}, dist + 1});
33                }
34            }
35        }
36        return (ans == 0 ) ? -1 : ans ;
37    }
38};