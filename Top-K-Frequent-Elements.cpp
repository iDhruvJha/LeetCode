1class Solution {
2public:
3    vector<int> topKFrequent(vector<int>& nums, int k) {
4        int n = nums.size() ;
5        unordered_map<int,int> mp ;
6        priority_queue<pair<int,int>> pq;     
7        for(auto it : nums){
8            mp[it]++ ;
9        }
10        for(auto it : mp ){
11            pq.push({it.second,it.first}) ;
12        }
13        vector<int> ans ;
14        while(k-- && !pq.empty()){
15            auto [p,q] = pq.top() ;
16            pq.pop() ;
17            ans.push_back(q) ;
18        }
19        return ans ;
20    }
21};