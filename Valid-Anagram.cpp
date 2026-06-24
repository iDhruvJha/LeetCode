1class Solution {
2public:
3    bool isAnagram(string s, string t) {
4        if( s.size() != t.size() ) return false ; 
5        unordered_map<char,int> mp ;
6        for(auto it : s){
7            mp[it]++ ;
8        }
9        for(auto it : t){
10            if(mp.count(it)){
11                mp[it]-- ;
12                if(mp[it] == 0){
13                    mp.erase(it) ;
14                }
15            }
16            else{
17                return false ;
18            }
19        }
20        return true ;
21    }
22};