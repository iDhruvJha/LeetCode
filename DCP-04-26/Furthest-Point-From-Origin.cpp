1class Solution {
2public:
3    int furthestDistanceFromOrigin(string moves) {
4        int l = 0 ; int r = 0 ; int notr = 0 ;
5        for( int i = 0 ; i < moves.size() ; i++ ){
6            if( moves[i] == 'L' ) l++ ;
7            else if( moves[i] == 'R' ) r++ ;
8            else notr++ ;
9        }
10        return max(l,r) + notr - min(l,r) ;
11    }
12};