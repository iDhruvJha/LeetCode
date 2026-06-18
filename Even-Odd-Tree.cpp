1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
10 * right(right) {}
11 * };
12 */
13class Solution {
14public:
15    bool isEvenOddTree(TreeNode* root) {
16        queue<TreeNode*> q;
17        q.push(root);
18        bool ch = true;
19        while (!q.empty()) {
20            int sz = q.size();
21            vector<int> v(sz);
22            for (int i = 0; i < sz; i++) {
23                auto node = q.front();
24                q.pop();
25                v[i] = node->val;
26                if (node->left)
27                    q.push(node->left);
28                if (node->right)
29                    q.push(node->right);
30            }
31            if (ch) {
32                bool inc = true;
33                if( v[0] % 2 == 0 ) return false ;
34                for (int i = 1; i < v.size(); i++) {
35                    if (v[i] <= v[i - 1] || v[i] % 2 == 0) {
36                        return false ;
37                    }
38                }
39            } else {
40                bool dec = true;
41                if( v[0] % 2 == 1 ) return false ;
42                for (int i = 1; i < v.size(); i++) {
43                    if (v[i] >= v[i - 1] || v[i] % 2 == 1) {
44                        return false ;
45                    }
46                }
47            }
48
49            ch = !ch;
50        }
51        return true;
52    }
53};