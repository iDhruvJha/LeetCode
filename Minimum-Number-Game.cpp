1class Solution {
2public:
3    vector<int> numberGame(vector<int>& nums) {
4        priority_queue<int, vector<int>, greater<int>> pq;
5        for(auto it : nums){
6            pq.push(it) ;
7        }
8        vector<int> ans ;
9        while(!pq.empty()){
10            int second = pq.top() ; pq.pop() ;
11            int first = pq.top() ; pq.pop() ;
12            ans.push_back(first);
13            ans.push_back(second) ;
14        }
15        return ans ;
16    }
17};