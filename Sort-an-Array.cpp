1class Solution {
2public:
3    void merge( int low , int high , int mid , vector<int>& nums){
4        int n1 = mid - low + 1 ;
5        int n2 = high - mid ;
6        vector<int> L(n1) , R(n2) ;
7        for(int i = 0 ; i < n1 ; i++ ){
8            L[i] = nums[low + i] ;
9        }
10        for(int i = 0 ; i < n2 ; i++ ){
11            R[i] = nums[ mid + 1 + i] ;
12        }
13        int i = 0 ;
14        int j = 0 ;
15        int k = low ;
16        while(i < n1 && j < n2){
17            if(L[i] <= R[j]){
18                nums[k] = L[i] ;
19                i++ ;
20                k++ ;
21            }
22            else{
23                nums[k] = R[j] ;
24                j++ ;
25                k++ ;
26            }
27        }
28        while(i < n1){
29            nums[k] = L[i] ;
30            i++ ;
31            k++ ;
32        }
33        while(j < n2){
34            nums[k] = R[j] ;
35            j++ ;
36            k++ ;
37        }
38    }
39    void mergesort(int low , int high , vector<int>& nums){
40        if( low >= high) return ;
41        int mid = low + ( high - low )/2 ;
42        mergesort(low,mid,nums) ;
43        mergesort(mid+1,high,nums) ;
44        merge(low,high,mid,nums) ;
45    }
46    vector<int> sortArray(vector<int>& nums) {
47        int n = nums.size() ;
48        mergesort(0,n-1,nums) ;
49        return nums ;
50    }
51};