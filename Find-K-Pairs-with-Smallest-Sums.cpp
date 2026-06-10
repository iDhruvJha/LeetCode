1class Solution {
2public:
3    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
4        vector<vector<int>> ans ;
5        if( k == 0 || nums1.empty() || nums2.empty()) return ans ;
6        using T = tuple<int,int,int> ;
7        priority_queue<T,vector<T>,greater<T>> pq ;
8        set<pair<int,int>> vis ;
9        pq.push({nums1[0] + nums2[0] , 0 , 0 }) ;
10        vis.insert({0,0}) ;
11        while(k-- && !pq.empty()){
12            auto [sum , i , j ] = pq.top() ; pq.pop() ;
13            ans.push_back({nums1[i],nums2[j]}) ;
14
15            if( i + 1 < nums1.size() && !vis.count({i+1,j})){
16                pq.push({nums1[i+1]+nums2[j],i+1,j}) ;
17                vis.insert({i+1,j}) ;
18            }
19            if( j + 1 < nums2.size() && !vis.count({i,j+1})){
20                pq.push({nums1[i]+nums2[j+1],i,j+1}) ;
21                vis.insert({i,j+1}) ;
22            }
23        }
24        return ans ;
25    }
26};