1class Solution {
2public:
3    int mySqrt(int x) {
4        int ans = -1;
5        int l = 0, r = x;
6
7        while (l <= r) {
8            long long mid = l + (r - l) / 2;
9
10            if (mid * mid <= x) {
11                ans = mid;
12                l = mid + 1;
13            } else {
14                r = mid - 1;
15            }
16        }
17        return ans;
18    }
19};