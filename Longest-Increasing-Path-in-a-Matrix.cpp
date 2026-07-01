1class Solution {
2public:
3    int m, n;
4    vector<vector<int>> dp;
5    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
6
7    int dfs(int i, int j, vector<vector<int>>& matrix) {
8        if (dp[i][j] != -1)
9            return dp[i][j];
10
11        int ans = 1;
12
13        for (auto &d : dir) {
14            int ni = i + d[0];
15            int nj = j + d[1];
16
17            if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
18                matrix[ni][nj] > matrix[i][j]) {
19                ans = max(ans, 1 + dfs(ni, nj, matrix));
20            }
21        }
22
23        return dp[i][j] = ans;
24    }
25
26    int longestIncreasingPath(vector<vector<int>>& matrix) {
27        m = matrix.size();
28        n = matrix[0].size();
29
30        dp.assign(m, vector<int>(n, -1));
31
32        int ans = 0;
33
34        for (int i = 0; i < m; i++) {
35            for (int j = 0; j < n; j++) {
36                ans = max(ans, dfs(i, j, matrix));
37            }
38        }
39
40        return ans;
41    }
42};