1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        int n = nums.size() ;
5        int zeros = 0 ;
6        int product = 1 ;
7        vector<int> ans(n,0) ; int ind = -1 ;
8        for( int i = 0 ; i < n ; i++ ){
9            if( nums[i] == 0 ){
10                zeros++ ;
11                if( zeros > 1 ){
12                    return ans ;
13                }
14                ind = i ;
15            }
16            else{
17                product *= nums[i] ;
18            }
19        }
20        if( zeros == 1 ){
21            ans[ind] = product ;
22            return ans ;
23        }
24        for( int i = 0 ; i < n ; i++ ){
25            ans[i] = product/nums[i] ;
26        }
27        return ans ;
28    }
29};