1class Solution {
2public:
3    int maxIceCream(vector<int>& costs, int coins) {
4        int n = costs.size() ;
5        sort(costs.begin(),costs.end()) ;
6        int i = 0 ; int count = 0 ;
7        while( i < n && costs[i] <= coins){
8            coins -= costs[i] ;
9            i++ ;
10            count++ ;
11        }
12        return count ;
13    }
14};