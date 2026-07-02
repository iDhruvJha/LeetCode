1class Solution {
2public:
3    int m, n;
4
5    bool dfs(int i, int j, vector<vector<int>>& grid) {
6
7        if (i < 0 || i >= m || j < 0 || j >= n)
8            return false;
9
10        if (grid[i][j] == 1)
11            return true;
12
13        grid[i][j] = 1;
14
15        bool up = dfs(i - 1, j, grid);
16        bool down = dfs(i + 1, j, grid);
17        bool left = dfs(i, j - 1, grid);
18        bool right = dfs(i, j + 1, grid);
19
20        return up && down && left && right;
21    }
22
23    int closedIsland(vector<vector<int>>& grid) {
24
25        m = grid.size();
26        n = grid[0].size();
27
28        int ans = 0;
29
30        for (int i = 0; i < m; i++) {
31            for (int j = 0; j < n; j++) {
32
33                if (grid[i][j] == 0) {
34                    if (dfs(i, j, grid))
35                        ans++;
36                }
37            }
38        }
39
40        return ans;
41    }
42};