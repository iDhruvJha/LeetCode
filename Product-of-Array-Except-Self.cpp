1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        int n = nums.size() ;
5        long long tp = 1 ;
6        bool ch = false ;
7        int ind = -1 ;
8        for(int i = 0 ; i < n ; i++ ){
9            if(nums[i] != 0 || ch ){
10                tp *= nums[i] ;
11            }
12            else{
13                ch = true ;
14                ind = i ;
15            }
16        }
17        vector<int> ans(n,0) ;
18        if(!tp && ch) return ans ;
19        if(ch){
20            ans[ind] = tp ;
21            return ans ;
22        }
23        for(int i = 0 ; i < n ; i++ ){
24            ans[i] = tp/nums[i] ;
25        }
26        return ans ;
27    }
28};