1class Solution {
2public:
3    int longestArithSeqLength(vector<int>& nums) {
4        int n = nums.size();
5        if(n <= 2) return n;
6        vector<vector<int>>dp(n, vector<int>(1001, 0));
7        int maxLen = 2;
8        for(int i = 1; i < n; i++){
9            for(int prev = 0; prev < i; prev++){
10                int diff = nums[i] - nums[prev];
11                int idxDiff = diff + 500;
12                dp[i][idxDiff] = dp[prev][idxDiff] > 0 ? dp[prev][idxDiff] + 1 : 2;
13                maxLen = max(maxLen, dp[i][idxDiff]);
14            }
15        }
16        return maxLen;
17    }
18};