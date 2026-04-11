1class Solution {
2public:
3    int minimumDistance(vector<int>& nums) {
4        int ans = INT_MAX ; int n = nums.size() ;
5        unordered_map<int,vector<int>> mp ;
6        for(int i = 0 ; i < n ; i++){
7            mp[nums[i]].push_back(i) ;
8        }
9        for( auto it : mp ){
10            vector<int>& v = it.second;
11            if(v.size() > 2 ){
12                for( int i = 2 ; i < v.size() ; i++ ){
13                    ans = min(ans,abs(v[i] - v[i-1]) + abs(v[i-2] - v[i-1]) + abs(v[i] - v[i-2])) ;
14                }
15            }
16        }
17        return (ans == INT_MAX) ? -1 : ans ;
18    }
19};