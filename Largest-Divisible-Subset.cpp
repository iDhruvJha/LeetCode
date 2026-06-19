1class Solution {
2public:
3    vector<int> largestDivisibleSubset(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5        vector<int> dp(nums.size(), 1), prev(nums.size(), -1);
6        int maxi = 0;
7        for (int i = 1; i < nums.size(); i++) {
8            for (int j = 0; j < i; j++) {
9                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
10                    dp[i] = dp[j] + 1;
11                    prev[i] = j;
12                }
13            }
14            if (dp[i] > dp[maxi]) maxi = i;
15        }
16        vector<int> res;
17        for (int i = maxi; i >= 0; i = prev[i]) {
18            res.push_back(nums[i]);
19        }
20        return res;
21    }
22};