1class Solution {
2public:
3    void merge(int s , int mid , int e ,vector<int>& nums){
4        int L1 = mid - s ;
5        int L2 = e - mid + 1 ;
6        vector<int> L(L1) , R(L2) ;
7        for( int i = 0 ; i < L1 ; i++ ){
8            L[i] = nums[s+i] ;
9        }
10        for( int i = 0 ; i < L2 ; i++ ){
11            R[i] = nums[mid+i] ;
12        }
13        int k = s ; int i = 0 ; int j = 0 ;
14        while(i < L1 && j < L2){
15            if( L[i] >= R[j]){
16                nums[k++] = R[j] ;
17                j++ ;
18            }
19            else{
20                nums[k++] = L[i] ;
21                i++ ;
22            }
23        }
24        while( i < L1 ){
25            nums[k++] = L[i] ;
26            i++ ;
27        }
28        while( j < L2 ){
29            nums[k++] = R[j] ;
30            j++ ;
31        }
32    }
33    void mergesort(int s , int e , vector<int>& nums){
34        if( s >= e ) return ;
35        int mid = s + ( e - s )/2 ;
36        mergesort(s,mid,nums) ;
37        mergesort(mid+1,e,nums) ;
38        merge(s,mid+1,e,nums) ;
39    }
40    vector<int> sortArray(vector<int>& nums) {
41        int n = nums.size() ;
42        mergesort(0,n-1,nums) ;
43        return nums ;
44    }
45};