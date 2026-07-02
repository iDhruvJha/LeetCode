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
14    unordered_map<int, TreeNode*> roots;
15
16    bool dfs(TreeNode* root, long low, long high) {
17
18        if (!root)
19            return true;
20
21        if (root->val <= low || root->val >= high)
22            return false;
23
24        // merge if current node is a leaf and another tree starts here
25        if (!root->left && !root->right && roots.count(root->val) && roots[root->val] != root) {
26
27            TreeNode* t = roots[root->val];
28
29            root->left = t->left;
30            root->right = t->right;
31
32            roots.erase(root->val);
33        }
34
35        return dfs(root->left, low, root->val) &&
36               dfs(root->right, root->val, high);
37    }
38
39    TreeNode* canMerge(vector<TreeNode*>& trees) {
40
41        unordered_set<int> leaves;
42
43        for (auto root : trees) {
44
45            roots[root->val] = root;
46
47            if (root->left)
48                leaves.insert(root->left->val);
49
50            if (root->right)
51                leaves.insert(root->right->val);
52        }
53
54        TreeNode* root = nullptr;
55
56        for (auto t : trees) {
57
58            if (!leaves.count(t->val)) {
59
60                if (root)
61                    return nullptr; // multiple possible roots
62
63                root = t;
64            }
65        }
66
67        if (!root)
68            return nullptr;
69
70        if (!dfs(root, LONG_MIN, LONG_MAX))
71            return nullptr;
72
73        if (roots.size() != 1)
74            return nullptr;
75
76        return root;
77    }
78};