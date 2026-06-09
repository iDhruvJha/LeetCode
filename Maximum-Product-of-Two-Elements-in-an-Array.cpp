1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        int n = nums.size() ;
5        priority_queue<int> pq;
6        for(auto it : nums){
7            pq.push(it) ;
8        }
9        int t = pq.top() ; pq.pop() ;
10        return (t-1)*(pq.top() - 1) ;
11    }
12};