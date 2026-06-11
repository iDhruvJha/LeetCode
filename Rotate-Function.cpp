1class Solution {
2public:
3    int maxRotateFunction(vector<int>& nums) {
4        int n = nums.size() ;
5        int F = 0 ;
6        int sum = 0 ;
7        for( int i = 0 ; i < n ; i++ ){
8            sum += nums[i] ;
9            F += i*nums[i] ;
10        }
11        int ans = F ;
12        for( int i = 1 ; i < n ; i++ ){
13            F += sum - n*nums[n-i] ;
14            ans = max(ans,F) ;
15        }
16        return ans ;
17    }
18};