1class Solution {
2public:
3    bool seen[16] = {} ;
4    int count = 0 ;
5    int dfs(int n , int pos){
6        if( pos > n ) return count++ ;
7        for( int i = 1 ; i <= n ; i++ ){
8            if(!seen[i] && ( (pos % i == 0) || ( i % pos == 0 ))){
9                seen[i] = true ;
10                dfs(n,pos+1) ;
11                seen[i] = false ;
12            }
13        }
14        return count ;
15    }
16    int countArrangement(int n) {
17        if( n < 4 ) return n ;
18        return dfs(n,1) ;
19    }
20};