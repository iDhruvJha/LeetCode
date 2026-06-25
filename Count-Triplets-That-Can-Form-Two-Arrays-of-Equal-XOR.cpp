1class Solution {
2public:
3    int countTriplets(vector<int>& arr) {
4        int count = 0;
5        
6        for (int i = 0; i < arr.size(); i++) {
7            int val = arr[i];
8            
9            for (int k = i + 1; k < arr.size(); k++) {
10                val ^= arr[k];
11                
12                if (val == 0) {
13                    count += (k - i);
14                }
15            }
16        }
17        
18        return count;
19    }
20};