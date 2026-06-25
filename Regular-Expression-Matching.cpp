1class Solution {
2public:
3    bool f(string &s,string &p,int i,int j){
4
5        int n=s.size();
6        int m=p.size();
7
8        if(i==n && j==m)
9            return true;
10
11        if(j==m)
12            return false;
13
14        if(i==n){
15            while(j+1<m && p[j+1]=='*')
16                j+=2;
17
18            return j==m;
19        }
20
21        bool match=(s[i]==p[j] || p[j]=='.');
22
23        if(j+1<m && p[j+1]=='*'){
24
25            return f(s,p,i,j+2) ||
26                  (match && f(s,p,i+1,j));
27
28        }
29
30        if(match)
31            return f(s,p,i+1,j+1);
32
33        return false;
34    }
35
36    bool isMatch(string s, string p) {
37        return f(s,p,0,0);
38    }
39};