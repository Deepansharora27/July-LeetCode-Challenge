

/*
PROBLEM STATEMENT :  

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.

*/



class Solution {
public:
    int hammingDistance(int x, int y) {
        //We Have to Return the Number Of Positions , where Corresponding Bits are Different.
        bitset<256>binary1(x);
        bitset<256>binary2(y);
        
        int count=0 ; 
        
        int i=0 ; 
        int j=0 ; 
        
        while(i<binary1.size() && j<binary2.size()){
            if(binary1[i] != binary2[j]){
                count++ ; 
                i++ ; 
                j++ ; 
            }else{
                i++ ; 
                j++ ; 
            }
        }
        
        return count;
    }
};