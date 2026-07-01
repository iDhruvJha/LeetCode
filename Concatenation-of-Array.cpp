1class Solution {
2public:
3    vector<int> getConcatenation(vector<int>& nums) {
4        int n = nums.size() ;
5        vector<int> ans(2*n,0) ;
6        for( int i = 0 ; i < 2*n ; i++ ){
7            ans[i] = nums[i%n] ;
8        }
9        return ans ;
10    }
11};