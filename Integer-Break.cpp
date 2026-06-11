1class Solution {
2public:
3    int integerBreak(int n) {
4        vector<int> dp(n + 1, 0);
5        dp[1] = 1;
6        for (int i = 2; i <= n; ++i) {
7            for (int j = 1; j < i; ++j) {
8                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
9            }
10        }
11        return dp[n];
12    }
13};