1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Solution {
11public:
12    unordered_map<TreeNode*, TreeNode*> parent;
13
14    void dfs(TreeNode* root) {
15
16        if (!root)
17            return;
18
19        if (root->left) {
20            parent[root->left] = root;
21            dfs(root->left);
22        }
23
24        if (root->right) {
25            parent[root->right] = root;
26            dfs(root->right);
27        }
28    }
29
30    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
31
32        dfs(root);
33
34        queue<TreeNode*> q;
35        unordered_set<TreeNode*> vis;
36
37        q.push(target);
38        vis.insert(target);
39
40        int dist = 0;
41
42        while (!q.empty()) {
43
44            int sz = q.size();
45
46            if (dist == k)
47                break;
48
49            while (sz--) {
50
51                TreeNode* node = q.front();
52                q.pop();
53
54                if (node->left && !vis.count(node->left)) {
55                    vis.insert(node->left);
56                    q.push(node->left);
57                }
58
59                if (node->right && !vis.count(node->right)) {
60                    vis.insert(node->right);
61                    q.push(node->right);
62                }
63
64                if (parent.count(node) && !vis.count(parent[node])) {
65                    vis.insert(parent[node]);
66                    q.push(parent[node]);
67                }
68            }
69
70            dist++;
71        }
72
73        vector<int> ans;
74
75        while (!q.empty()) {
76            ans.push_back(q.front()->val);
77            q.pop();
78        }
79
80        return ans;
81    }
82};