1class Solution {
2public:
3    vector<string> generateValidStrings(int n, int k) {
4        vector<string> a ;
5        string cur ;
6        function<void(int,int,int)>me = [&](int i,int c , int p){
7            if(c > k ) return ;
8            if(i == n){
9                a.push_back(cur) ;
10                return ;
11            }
12            cur.push_back('0') ;
13            me(i + 1 , c , 0 ) ;
14            cur.pop_back() ;
15            if(p == 0 ){
16                cur.push_back('1') ;
17                me(i+1,c+i,1) ;
18                cur.pop_back() ;
19            }
20        };
21        me(0,0,0) ;
22        return a ;
23    }
24};