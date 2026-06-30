1class Solution {
2public:
3    int maxCoins(vector<int>& nums) {
4
5        nums.insert(nums.begin(),1);
6        nums.push_back(1);
7
8        int n=nums.size();
9
10        vector<vector<int>> dp(n,vector<int>(n,0));
11
12        for(int i=n-2;i>=1;i--)
13        {
14            for(int j=i;j<=n-2;j++)
15            {
16                int ans=0;
17
18                for(int k=i;k<=j;k++)
19                {
20                    int coins = nums[i-1]*nums[k]*nums[j+1];
21
22                    coins += dp[i][k-1];
23
24                    coins += dp[k+1][j];
25
26                    ans=max(ans,coins);
27                }
28
29                dp[i][j]=ans;
30            }
31        }
32
33        return dp[1][n-2];
34    }
35};