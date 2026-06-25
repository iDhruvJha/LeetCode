1class Solution {
2public:
3    int countTriplets(vector<int>& arr) {
4        int n = arr.size() ;
5        vector<int> prefix(n,0) ;
6        prefix[0] = arr[0] ;
7        for(int i = 1 ; i < n ; i++ ){
8            prefix[i] = prefix[i-1]^arr[i] ;
9        } 
10        int count = 0 ;
11        for(int j = 1 ; j < n ; j++){
12            for( int i = 0 ; i < j ; i++ ){
13                for(int k = j ; k < n ; k++ ){
14                    int a = 0 ;
15                    a = ( i - 1 >= 0 ) ? prefix[j-1]^prefix[i-1] : prefix[j-1] ;
16                    int  b = prefix[k]^prefix[j-1] ;
17                    if(a == b) count++ ;
18                }
19            }
20        }
21        return count ;
22    }
23};