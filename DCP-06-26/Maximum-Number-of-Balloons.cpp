1class Solution {
2public:
3    int maxNumberOfBalloons(string text) {
4        unordered_map<char,int> freq;
5        for(char c:text){
6            freq[c]++;
7        }
8        return min({freq['b'],freq['a'],freq['l']/2,freq['o']/2,freq['n']});
9    }
10};