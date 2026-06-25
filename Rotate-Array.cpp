1class Solution {
2public:
3    void f(vector<int>& nums, int l , int r ){
4        int sz = (r - l + 1)/2 ;
5        for( int i = 0 ; i < sz ; i++ ){
6            swap(nums[l+i],nums[r-i]) ;
7        }
8    }
9    void rotate(vector<int>& nums, int k) {
10        int n = nums.size() ;
11        k = k%nums.size() ;
12        f(nums,0,n-k-1) ;
13        f(nums,n-k,n-1) ;
14        f(nums,0,n-1) ;
15        return ;
16    }
17};