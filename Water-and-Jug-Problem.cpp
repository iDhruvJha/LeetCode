1class Solution {
2public:
3    bool canMeasureWater(int x, int y, int target) {
4
5        if (target > x + y)
6            return false;
7
8        return target % gcd(x, y) == 0;
9    }
10};
11
12// Bézout's identity is a fundamental theorem in number theory stating that for any two non-zero integers \(a\) and \(b\), their greatest common divisor (GCD) can be expressed as a linear combination of the two.