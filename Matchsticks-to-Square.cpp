1class Solution {
2public:
3    bool makesquare(vector<int>& nums) {
4        int n = nums.size();
5
6        int sum = accumulate(nums.begin(), nums.end(), 0);
7
8        if (sum % 4) return false;
9
10        int target = sum / 4;
11
12        vector<int> dp(1 << n, -1);
13        dp[0] = 0;
14
15        for (int mask = 0; mask < (1 << n); mask++) {
16
17            if (dp[mask] == -1) continue;
18
19            for (int i = 0; i < n; i++) {
20
21                if (mask & (1 << i)) continue;
22
23                if (dp[mask] + nums[i] > target) continue;
24
25                int newMask = mask | (1 << i);
26
27                dp[newMask] = (dp[mask] + nums[i]) % target;
28            }
29        }
30
31        return dp[(1 << n) - 1] == 0;
32    }
33};