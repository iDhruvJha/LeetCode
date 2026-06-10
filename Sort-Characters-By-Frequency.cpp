1class Solution {
2public:
3    string frequencySort(string s) {
4        int n = s.size() ;
5        unordered_map<int,int> mp ;
6        for(auto it : s ){
7            mp[it]++ ;
8        }
9        priority_queue<pair<int,char>> pq;
10        for(auto it : mp){
11            pq.push({it.second,it.first}) ;
12        }
13        string ans ;
14        while(!pq.empty()){
15            auto [p,q] = pq.top() ; pq.pop() ;
16            while(p--){
17                ans.push_back(q) ;
18            }
19        }
20        return ans ;
21    }
22};