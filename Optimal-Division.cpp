1class Solution {
2public:
3    string optimalDivision(vector<int>& nums) {
4        string ans="";
5        if(!nums.size()) 
6            return ans;
7
8        ans += to_string(nums[0]);
9
10        if(nums.size()==1)
11            return ans;
12
13        if(nums.size()==2)
14            return ans += "/" + to_string(nums[1]);
15
16        ans += "/(" + to_string(nums[1]);
17
18        for(int i=2;i<nums.size();i++){
19            ans += "/" + to_string(nums[i]);
20        }
21
22        ans += ")";
23        return ans;
24    }
25};