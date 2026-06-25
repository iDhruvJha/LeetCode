1class Solution {
2public:
3    vector<int> plusOne(vector<int>& digits) {
4        int n = digits.size() ;
5        int i = n - 1 ;
6        while( i >= 0 && digits[i] == 9 ){
7            digits[i] = 0 ;
8            i-- ;
9        }
10        if( i >= 0 ) digits[i]++ ;
11        else{
12            digits.insert(digits.begin(), 1);
13        }
14        return digits ;
15    }
16};