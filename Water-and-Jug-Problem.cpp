1class Solution {
2public:
3    bool canMeasureWater(int x, int y, int target) {
4
5        if(target > x + y)
6            return false;
7
8        queue<pair<int,int>> q;
9        set<pair<int,int>> vis;
10
11        q.push({0,0});
12        vis.insert({0,0});
13
14        while(!q.empty()){
15
16            auto [a,b] = q.front();
17            q.pop();
18
19            if(a==target || b==target || a+b==target)
20                return true;
21
22            vector<pair<int,int>> next;
23
24            // Fill jug1
25            next.push_back({x,b});
26
27            // Fill jug2
28            next.push_back({a,y});
29
30            // Empty jug1
31            next.push_back({0,b});
32
33            // Empty jug2
34            next.push_back({a,0});
35
36            // Pour jug1 -> jug2
37            int t=min(a,y-b);
38            next.push_back({a-t,b+t});
39
40            // Pour jug2 -> jug1
41            t=min(b,x-a);
42            next.push_back({a+t,b-t});
43
44            for(auto state:next){
45                if(!vis.count(state)){
46                    vis.insert(state);
47                    q.push(state);
48                }
49            }
50        }
51
52        return false;
53    }
54};