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
14
15    map<int, map<int, multiset<int>>> mp;
16
17    void dfs(TreeNode* root, int row, int col) {
18
19        if (!root)
20            return;
21
22        mp[col][row].insert(root->val);
23
24        dfs(root->left, row + 1, col - 1);
25        dfs(root->right, row + 1, col + 1);
26    }
27
28    vector<vector<int>> verticalTraversal(TreeNode* root) {
29
30        dfs(root, 0, 0);
31
32        vector<vector<int>> ans;
33
34        for (auto &col : mp) {
35
36            vector<int> temp;
37
38            for (auto &row : col.second) {
39
40                for (int val : row.second)
41                    temp.push_back(val);
42            }
43
44            ans.push_back(temp);
45        }
46
47        return ans;
48    }
49};