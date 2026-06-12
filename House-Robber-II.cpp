1class Solution {
2public:
3    int f(vector<int>& nums) {
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
15    int rob(vector<int>& nums) {
16        int n = nums.size() ;
17        if( n == 1 ) return nums[0] ;
18        vector<int> temp1(n-1,0) ;
19        vector<int> temp2(n-1,0) ;
20        for( int i = 0 ; i < n ; i++ ){
21            if( i != 0 ){
22                temp1.push_back(nums[i]) ;
23            }
24            if( i != n - 1 ){
25                temp2.push_back(nums[i]) ;
26            }
27        }
28        return max(f(temp1),f(temp2)) ;
29    }
30};