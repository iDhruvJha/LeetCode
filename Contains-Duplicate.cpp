1class Solution {
2public:
3    bool containsDuplicate(vector<int>& nums) {
4        int n = nums.size() ;
5        unordered_map<int,int> mp ;
6        for(auto it : nums)
7            mp[it]++ ;
8        for(auto it : mp){
9            if(it.second > 1 ) return true ;
10        }
11        return false ;
12    }
13};