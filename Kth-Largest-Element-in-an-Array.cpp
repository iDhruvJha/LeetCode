1class Solution {
2public:
3    int findKthLargest(vector<int>& nums, int k) {
4        priority_queue<int> pq;
5        for(auto it : nums){
6            pq.push(it) ;
7        }
8        k-- ;
9        while(k--){
10            pq.pop() ;
11        }
12        return pq.top() ;
13    }
14};