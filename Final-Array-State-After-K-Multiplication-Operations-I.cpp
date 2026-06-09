1class Solution {
2public:
3    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
4        int n = nums.size() ;
5        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
6        for(int i = 0 ; i < n ; i++){
7            pq.push({nums[i],i}) ;
8        }
9        while(k--){
10            auto it = pq.top() ;
11            pq.pop() ;
12            nums[it.second] *= multiplier ;
13            pq.push({nums[it.second],it.second}) ;
14        }
15        return nums ;
16    }
17};