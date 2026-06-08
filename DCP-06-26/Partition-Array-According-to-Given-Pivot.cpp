1class Solution {
2public:
3    vector<int> pivotArray(vector<int>& nums, int pivot) {
4        int n = nums.size() ;
5        vector<int> ans(n,0) ;
6        int i = 0 ; int cnt = 0 ;
7        for(auto& it : nums){
8            if(it < pivot){
9                ans[i++] = it ;
10            }
11            else if(it == pivot){
12                cnt++ ;
13            }
14        }
15        while(cnt--){
16            ans[i++] = pivot ;
17        }
18        for(auto& it : nums){
19            if(it > pivot){
20                ans[i++] = it ;
21            }
22        }
23        return ans ;
24    }
25};