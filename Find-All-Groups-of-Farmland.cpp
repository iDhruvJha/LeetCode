1class Solution {
2public:
3    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
4
5        int m = land.size();
6        int n = land[0].size();
7
8        vector<vector<int>> ans;
9
10        for (int i = 0; i < m; i++) {
11
12            for (int j = 0; j < n; j++) {
13
14                if (land[i][j] == 1 &&
15                    (i == 0 || land[i - 1][j] == 0) &&
16                    (j == 0 || land[i][j - 1] == 0)) {
17
18                    int r = i;
19                    int c = j;
20
21                    while (r + 1 < m && land[r + 1][j] == 1)
22                        r++;
23
24                    while (c + 1 < n && land[i][c + 1] == 1)
25                        c++;
26
27                    ans.push_back({i, j, r, c});
28                }
29            }
30        }
31
32        return ans;
33    }
34};