1class Solution {
2public:
3    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
4        int n = arr.size() ;
5        vector<int> prefix(n,0) ;
6        prefix[0] = arr[0] ;
7        for(int i = 1 ; i < n ; i++ ){
8            prefix[i] = prefix[i-1]^arr[i] ;
9        } 
10        vector<int> ans ;
11        for(auto it : queries){
12            int l = it[0] ;
13            int r = it[1] ;
14            int t = ( l - 1 >= 0 ) ? prefix[r]^prefix[l-1] : prefix[r] ;
15            ans.push_back(t) ;
16        }
17        return ans ;
18    }
19};