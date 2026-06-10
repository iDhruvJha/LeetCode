1class Solution {
2public:
3    vector<string> generateParenthesis(int n) {
4        vector<string> res;
5        dfs(0, 0, "", n, res);
6        return res;        
7    }
8
9private:
10    void dfs(int openP, int closeP, string s, int n, vector<string>& res) {
11        if (openP == closeP && openP + closeP == n * 2) {
12            res.push_back(s);
13            cout << s << endl ;
14            return;
15        }
16
17        if (openP < n) {
18            dfs(openP + 1, closeP, s + "(", n, res);
19        }
20
21        if (closeP < openP) {
22            dfs(openP, closeP + 1, s + ")", n, res);
23        }
24    }
25};