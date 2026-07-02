1class Solution {
2public:
3    int m, n;
4    vector<vector<int>> vis;
5    vector<pair<int, int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
6
7    long long dfs(int i, int j, vector<vector<int>>& grid) {
8        vis[i][j] = 1;
9        long long sum = grid[i][j];
10
11        for (auto &d : dir) {
12            int ni = i + d.first;
13            int nj = j + d.second;
14
15            if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
16                !vis[ni][nj] && grid[ni][nj] > 0) {
17                sum += dfs(ni, nj, grid);
18            }
19        }
20
21        return sum;
22    }
23
24    int countIslands(vector<vector<int>>& grid, int k) {
25        m = grid.size();
26        n = grid[0].size();
27
28        vis.assign(m, vector<int>(n, 0));
29
30        int ans = 0;
31
32        for (int i = 0; i < m; i++) {
33            for (int j = 0; j < n; j++) {
34                if (grid[i][j] > 0 && !vis[i][j]) {
35                    long long sum = dfs(i, j, grid);
36                    if (sum % k == 0)
37                        ans++;
38                }
39            }
40        }
41
42        return ans;
43    }
44};