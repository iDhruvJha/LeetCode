1class Solution {
2public:
3    int combinationSum4(vector<int>& nums, int target) {
4        int n = nums.size() ;
5        vector<unsigned int> dp(target+1) ;
6        dp[0] = 1 ;
7        for( int i = 1 ; i <= target ; i++ ){
8            for( auto num : nums ){
9                if( i - num >= 0 ){
10                    dp[i] += dp[i-num] ;
11                }
12            }
13        }
14        return dp[target] ;
15    }
16};