1class Solution {
2public:
3    unordered_map<int, int> mp;
4    int f(TreeNode* root) {
5        if (!root)
6            return 0;
7        int leftt = f(root->left);
8        int rightt = f(root->right);
9        mp[leftt + rightt + root->val]++;
10        return leftt + rightt + root->val;
11    }
12    vector<int> findFrequentTreeSum(TreeNode* root) {
13        vector<int> ans;
14        f(root);
15        int mx = 0;
16        for (auto& it : mp) {
17            mx = max(mx, it.second);
18        }
19
20        for (auto& it : mp) {
21            if (it.second == mx)
22                ans.push_back(it.first);
23        }
24        return ans ;
25    }
26};