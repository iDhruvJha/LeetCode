1class Solution {
2public:
3    int f(vector<string>& garbage, vector<int>& prefix, char ch){
4        int n = prefix.size() ;
5        int ind = -1 ; int count = 0 ;
6        for(int i = 0 ; i < n ; i++ ){
7            for( int j = 0 ; j < garbage[i].size() ; j++ ){
8                if(garbage[i][j] == ch){
9                    count++ ;
10                    ind = i ;
11                }
12            }
13        }
14        return (ind == -1) ? 0 : count + prefix[ind] ;
15    }
16    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
17        int n = garbage.size() ;
18        vector<int> prefix(n,0) ;
19        for(int i = 1 ; i < n ; i++){
20            prefix[i] += prefix[i-1] + travel[i-1] ;
21        }
22        int ans = 0 ;
23        ans += f(garbage,prefix,'G') ;
24        ans += f(garbage,prefix,'P') ;
25        ans += f(garbage,prefix,'M') ;
26        return ans ;
27    }
28};