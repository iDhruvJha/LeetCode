1class Solution {
2public:
3    void dfs(vector<vector<int>>& vis, vector<vector<char>>& grid, int n, int m,
4             int row, int col) {
5        vis[row][col] = 1;
6        int dr[4] = {-1, 1, 0, 0};
7        int dc[4] = {0, 0, -1, 1};
8        for (int i = 0; i < 4; i++) {
9            int nr = row + dr[i];
10            int nc = col + dc[i];
11            if (nc >= 0 && nr < n && nr >= 0 && nc < m && !vis[nr][nc] &&
12                grid[nr][nc] == 'O') {
13                dfs(vis, grid, n, m, nr, nc);
14            }
15        }
16    }
17    void solve(vector<vector<char>>& board) {
18        int n = board.size();
19        int m = board[0].size();
20
21        vector<vector<int>> vis(n, vector<int>(m, 0));
22        for (int i = 0; i < n; i++) {
23            if (!vis[i][0] && board[i][0] == 'O') {
24                dfs(vis,board,n,m,i,0) ;
25            }
26        }
27        for (int i = 0; i < n; i++) {
28            if (!vis[i][m-1] && board[i][m-1] == 'O') {
29                dfs(vis,board,n,m,i,m-1) ;
30            }
31        }
32        for (int i = 0; i < m; i++) {
33            if (!vis[0][i] && board[0][i] == 'O') {
34                dfs(vis,board,n,m,0,i) ;
35            }
36        }
37        for (int i = 0; i < m; i++) {
38            if (!vis[n-1][i] && board[n-1][i] == 'O') {
39                dfs(vis,board,n,m,n-1,i) ;
40            }
41        }
42        for (int i = 0; i < n; i++) {
43            for (int j = 0; j < m; j++) {
44                if (!vis[i][j] && board[i][j] == 'O') {
45                    board[i][j] = 'X';
46                }
47            }
48        }
49    }
50};