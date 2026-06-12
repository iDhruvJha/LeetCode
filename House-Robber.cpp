1class Solution {
2public:
3    int rob(vector<int>& nums) {
4        int n = nums.size() ;
5        if( n == 1 ) return nums[0] ;
6        if( n == 2 ) return max(nums[1],nums[0]) ;
7        vector<int> dp(n,0) ;
8        dp[0] = nums[0] ;
9        dp[1] = max(nums[1],nums[0]) ;
10        for( int i = 2 ; i < n ; i++ ){
11            dp[i] = max(dp[i-1],dp[i-2] + nums[i]) ;
12        }
13        return dp[n-1] ;
14    }
15};