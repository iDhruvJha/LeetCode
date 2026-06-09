1class Solution {
2public:
3    vector<int> findXSum(vector<int>& nums, int k, int x) {
4        int n = nums.size();
5        unordered_map<int, int> mp;
6        priority_queue<int> pq;
7        int sz = n - k + 1;
8        vector<int> ans;
9        for (int i = 0; i < k; i++) {
10            mp[nums[i]]++;
11        }
12        vector<int> a;
13        for (int i = 0; i < n - k + 1; i++) {
14            if (i != 0)
15                mp[nums[k + i - 1]]++;
16            priority_queue<pair<int, int>> pq;
17            for (auto it : mp) {
18                pq.push({it.second, it.first});
19            }
20            int ans = 0;
21            for (int j = 0; j < x && !pq.empty(); j++) {
22                auto it = pq.top();
23                pq.pop();
24                ans += (it.second * it.first);
25            }
26            a.push_back(ans);
27            mp[nums[i]]--;
28
29            if (mp[nums[i]] == 0)
30                mp.erase(nums[i]);
31        }
32        return a;
33    }
34};