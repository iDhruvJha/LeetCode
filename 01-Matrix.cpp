1class Solution {
2public:
3    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
4        int n = mat.size();
5        int m = mat[0].size();
6        vector<vector<int>> dis(n, vector<int>(m, 0));
7        vector<vector<int>> vis(n, vector<int>(m, 0));
8        queue<pair<pair<int, int>, int>> q;
9        for (int i = 0; i < n; i++) {
10            for (int j = 0; j < m; j++) {
11                if (mat[i][j] == 0) {
12                    q.push({{i, j}, 0});
13                    vis[i][j] = 1;
14                }
15            }
16        }
17        int delrow[] = {0, 0, 1, -1};
18        int delcol[] = {1, -1, 0, 0};
19        while (!q.empty()) {
20            int row = q.front().first.first;
21            int col = q.front().first.second;
22            int dist = q.front().second;
23            q.pop();
24            dis[row][col] = dist;
25            for (int i = 0; i < 4; i++) {
26                int nrow = row + delrow[i];
27                int ncol = col + delcol[i];
28                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
29                       !vis[nrow][ncol] && mat[nrow][ncol] == 1) {
30                    vis[nrow][ncol] = 1;
31                    q.push({{nrow, ncol}, dist + 1});
32                }
33            }
34        }
35        return dis;
36    }
37};