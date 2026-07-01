1class Solution {
2public:
3    string longestCommonPrefix(vector<string>& strs) {
4        string ans = strs[0] ; int n = strs.size() ;
5        for(int i = 1 ; i < n ; i++ ){
6            string temp = "" ;
7            for( int j = 0 ; j < strs[i].size() ; j++ ){
8                if(ans[j] == strs[i][j]){
9                    temp += ans[j] ;
10                }
11                else{
12                    break ;
13                }
14            }
15            cout << temp << " " ;
16            ans = temp ;
17        }
18        return ans ;
19    }
20};