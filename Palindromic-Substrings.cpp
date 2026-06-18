1class Solution {
2public:
3    int countSubstrings(string s) {
4        int count = 0;
5        for (int i = 0; i < s.length(); i++) {
6            count += expand(s, i, i);
7            count += expand(s, i, i + 1);
8        }
9        return count;
10    }
11
12    int expand(string& s, int left, int right) {
13        int count = 0;
14        while (left >= 0 && right < s.length() && s[left] == s[right]) {
15            count++;
16            left--;
17            right++;
18        }
19        return count;
20    }
21};