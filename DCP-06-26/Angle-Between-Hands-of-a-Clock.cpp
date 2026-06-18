1class Solution {
2public:
3    double angleClock(int hour, int minutes) {
4        if( hour == 12 ){
5            hour = 0 ;
6        }
7        double ans = max(hour*30 + minutes*0.5,minutes*6.0) - min(hour*30 + minutes*0.5,minutes*6.0);
8        return (ans  > 180) ?  360 - ans : ans ;
9    }
10};