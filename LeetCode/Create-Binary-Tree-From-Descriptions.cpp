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
15    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
16        unordered_map<int, TreeNode*> mp;
17        unordered_set<int> child;
18
19        for (auto& d : descriptions) {
20            int parent = d[0];
21            int ch = d[1];
22            int isLeft = d[2];
23
24            if (!mp.count(parent))
25                mp[parent] = new TreeNode(parent);
26
27            if (!mp.count(ch))
28                mp[ch] = new TreeNode(ch);
29
30            if (isLeft)
31                mp[parent]->left = mp[ch];
32            else
33                mp[parent]->right = mp[ch];
34
35            child.insert(ch);
36        }
37
38        TreeNode* root = nullptr;
39
40        for (auto& d : descriptions) {
41            if (!child.count(d[0])) {
42                root = mp[d[0]];
43                break;
44            }
45        }
46
47        return root;
48    }
49};