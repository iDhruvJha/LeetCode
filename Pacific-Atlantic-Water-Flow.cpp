1class Solution {
2public:
3    int m, n;
4    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
5
6    void dfs(int i, int j, vector<vector<int>>& heights,
7             vector<vector<bool>>& vis) {
8
9        vis[i][j] = true;
10
11        for (auto &d : dir) {
12
13            int ni = i + d[0];
14            int nj = j + d[1];
15
16            if (ni < 0 || nj < 0 || ni >= m || nj >= n)
17                continue;
18
19            if (vis[ni][nj])
20                continue;
21
22            // Reverse flow condition
23            if (heights[ni][nj] >= heights[i][j])
24                dfs(ni, nj, heights, vis);
25        }
26    }
27
28    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
29
30        m = heights.size();
31        n = heights[0].size();
32
33        vector<vector<bool>> pacific(m, vector<bool>(n, false));
34        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
35
36        // Pacific (top row)
37        for (int j = 0; j < n; j++)
38            dfs(0, j, heights, pacific);
39
40        // Pacific (left column)
41        for (int i = 0; i < m; i++)
42            dfs(i, 0, heights, pacific);
43
44        // Atlantic (bottom row)
45        for (int j = 0; j < n; j++)
46            dfs(m - 1, j, heights, atlantic);
47
48        // Atlantic (right column)
49        for (int i = 0; i < m; i++)
50            dfs(i, n - 1, heights, atlantic);
51
52        vector<vector<int>> ans;
53
54        for (int i = 0; i < m; i++) {
55            for (int j = 0; j < n; j++) {
56                if (pacific[i][j] && atlantic[i][j])
57                    ans.push_back({i, j});
58            }
59        }
60
61        return ans;
62    }
63};