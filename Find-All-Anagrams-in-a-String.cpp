1class Solution {
2public:
3    vector<int> findAnagrams(string s, string p) {
4        int k = p.size() ;
5        int n = s.size() ;
6        vector<int> ans ;
7        if( k > n ) return ans ;
8        unordered_map<char,int> mp ;
9        unordered_map<char,int> mpp ;
10        for(auto it : p){
11            mp[it]++ ;
12        }
13        for(int i = 0 ; i < k ; i++){
14            mpp[s[i]]++ ;
15        }
16        if(mp == mpp) ans.push_back(0) ;
17
18        for(int i = k ; i < n ; i++ ){
19            mpp[s[i-k]]-- ;
20            if(mpp[s[i-k]] == 0)
21                mpp.erase(s[i-k]);
22            mpp[s[i]]++ ;
23            if( mp == mpp ){
24                ans.push_back(i - k + 1) ;
25            }
26        }
27        return ans ;
28    }
29};