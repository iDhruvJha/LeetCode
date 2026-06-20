1class Solution {
2public:
3    
4    int minLights(vector<int>& lights) {
5        vector<vector<int>> intervals;
6        int n = lights.size();
7        for(int i=0;i<n;i++){
8            if(lights[i] == 0){
9                continue;
10            }
11            int start = max(0,i-lights[i]);
12            int end = min(n-1,i+lights[i]);
13
14            intervals.push_back({start,end});
15        }
16        sort(intervals.begin(),intervals.end(),[](vector<int>&v1,vector<int>&v2){
17            return v1[0] < v2[0];
18        });
19
20        vector<vector<int>> new_intervals;
21
22        for(auto& i : intervals){
23            if(new_intervals.empty() || i[0] > new_intervals.back()[1]){
24                new_intervals.push_back(i);
25            }else{
26                new_intervals.back()[1] = max(new_intervals.back()[1],i[1]);
27            }
28        }
29
30
31        vector<int> lig(n,0);
32        for(auto& i : new_intervals){
33            for(int j = i[0];j<=i[1];j++){
34                lig[j] = 1;
35            }
36        }
37        int ans = 0;
38        for(int i =0;i<n;i++){
39            if(lig[i] == 0){
40                if(i+1 < n && lig[i+1] == 0){
41                    ans++;
42                    lig[i] = 1;
43                    lig[i+1] = 1;
44                    if(i+2 < n){
45                        lig[i+2] = 1;
46                    }
47                }else{
48                    ans++;
49                    lig[i] = 1;
50                }
51            }
52        }
53        return ans;
54    }
55};