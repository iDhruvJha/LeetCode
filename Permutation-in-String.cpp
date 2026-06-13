1class Solution {
2public:
3    bool checkInclusion(string s1, string s2) {
4        int k = s1.size() ;
5        int n = s2.size() ;
6        vector<int> ans ;
7        if( k > n ) return false ;
8        unordered_map<char,int> mp ;
9        unordered_map<char,int> mpp ;
10        for(auto it : s1){
11            mp[it]++ ;
12        }
13        for(int i = 0 ; i < k ; i++){
14            mpp[s2[i]]++ ;
15        }
16        if(mp == mpp) return true ;
17
18        for(int i = k ; i < n ; i++ ){
19            mpp[s2[i-k]]-- ;
20            if(mpp[s2[i-k]] == 0)
21                mpp.erase(s2[i-k]);
22            mpp[s2[i]]++ ;
23            if( mp == mpp ){
24                return true ;
25            }
26        }
27        return false ;
28    }
29};