1class Solution {
2public:
3    vector<int> pathInZigZagTree(int label) {
4        vector<int> result;
5        result.push_back(label); //taking bottom up approach, so the label itself must be included 
6        int height=log2(label); //height of label from root
7        
8        while(height!=0){
9            int left=pow(2,height-1); // rank of left limit of the previous level 
10            int right=pow(2,height)-1;// rank of right limit of the previous level
11            label=left+(right-label/2);// The previous level is sorted in different order than current one.
12                                       //So the new label is adjusted accordingly
13            result.push_back(label);  //newly found label is appened to result
14            height--;
15        }
16        
17        reverse(result.begin(),result.end()); //required top to down, so the array is reversed. 
18        return result;
19    }
20};