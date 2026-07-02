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
14    unordered_map<long long, int> mp;
15
16    int dfs(TreeNode* root, long long currSum, int targetSum) {
17        if (!root) return 0;
18
19        currSum += root->val;
20
21        int ans = mp[currSum - targetSum];
22
23        mp[currSum]++;
24
25        ans += dfs(root->left, currSum, targetSum);
26        ans += dfs(root->right, currSum, targetSum);
27
28        mp[currSum]--;
29
30        return ans;
31    }
32
33    int pathSum(TreeNode* root, int targetSum) {
34        mp[0] = 1;
35        return dfs(root, 0, targetSum);
36    }
37};