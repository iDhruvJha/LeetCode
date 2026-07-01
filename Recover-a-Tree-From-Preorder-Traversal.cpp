1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    TreeNode* recoverFromPreorder(string traversal) {
15
16        stack<TreeNode*> st;
17        int i = 0;
18        int n = traversal.size();
19
20        while (i < n) {
21
22            int depth = 0;
23            while (i < n && traversal[i] == '-') {
24                depth++;
25                i++;
26            }
27
28            int val = 0;
29            while (i < n && isdigit(traversal[i])) {
30                val = val * 10 + (traversal[i] - '0');
31                i++;
32            }
33
34            TreeNode* node = new TreeNode(val);
35
36            while (st.size() > depth)
37                st.pop();
38
39            if (!st.empty()) {
40                if (st.top()->left == NULL)
41                    st.top()->left = node;
42                else
43                    st.top()->right = node;
44            }
45
46            st.push(node);
47        }
48
49        while (st.size() > 1)
50            st.pop();
51
52        return st.top();
53    }
54};