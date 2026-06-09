1class Solution {
2public:
3    long long maxTotalValue(vector<int>& nums, int k) {
4        long long t = 1LL*(*max_element(nums.begin(),nums.end()) - *min_element(nums.begin(),nums.end()))*k;
5        return t ;
6    }
7};