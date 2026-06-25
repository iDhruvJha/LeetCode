1class Solution {
2public:
3    bool isMatch(string s, string p) {
4
5        int n = s.size();
6        int m = p.size();
7
8        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
9
10        dp[n][m] = true;
11
12        for (int j = m - 2; j >= 0; j--) {
13            if (p[j + 1] == '*')
14                dp[n][j] = dp[n][j + 2];
15        }
16
17        for (int i = n - 1; i >= 0; i--) {
18
19            for (int j = m - 1; j >= 0; j--) {
20
21                bool match = (s[i] == p[j] || p[j] == '.');
22
23                if (j + 1 < m && p[j + 1] == '*') {
24
25                    dp[i][j] = dp[i][j + 2] ||
26                               (match && dp[i + 1][j]);
27
28                } else {
29
30                    dp[i][j] = match && dp[i + 1][j + 1];
31
32                }
33            }
34        }
35
36        return dp[0][0];
37    }
38};