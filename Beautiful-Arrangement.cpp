1class Solution {
2public:
3    int seen = 0 ;
4    int count = 0 ;
5    int dfs(int n , int pos){
6        if( pos > n ) return count++ ;
7        for( int i = 1 ; i <= n ; i++ ){
8            int bit = 1 << i ;
9            if(!(seen & bit) && ( (pos % i == 0) || ( i % pos == 0 ))){
10                seen ^= bit ;
11                dfs(n,pos+1) ;
12                seen ^= bit ;
13            }
14        }
15        return count ;
16    }
17    int countArrangement(int n) {
18        if( n < 4 ) return n ;
19        return dfs(n,1) ;
20    }
21};