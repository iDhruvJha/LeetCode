1class Solution {
2public:
3    int countValidSubarrays(vector<int>& nums, int x) {
4        int n = nums.size() ; int count = 0 ;
5        for(int i = 0 ; i < n ; i++ ){
6            long long sum = 0 ;
7            for( int j = i ; j < n ; j++ ){
8                sum += nums[j] ;
9                long long temp = sum ;
10                int prev = -1 ;
11                while(temp > 0){
12                    prev = temp ;
13                    temp /= 10 ;
14                }
15                if( ((sum % 10) == x) && (prev == x)){
16                    count++ ;
17                    cout << sum << endl ;
18                }
19            }
20        }
21        return count ;
22    }
23};