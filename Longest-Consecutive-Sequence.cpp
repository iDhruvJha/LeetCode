1class Solution {
2public:
3    int longestConsecutive(vector<int>& nums) {
4        unordered_set<int> st(nums.begin(),nums.end()) ;
5        int n = nums.size() ;
6        int length = 0 ;
7        for( auto& num : st){
8            if( st.find(num - 1) == st.end()){
9                int curr = num ;
10                int len = 1 ;
11                while( st.find( curr + 1 ) != st.end()){
12                    curr++ ;
13                    len++ ;
14                }
15                length = max(length,len) ;
16            }
17        }
18        return length ;
19    }
20};