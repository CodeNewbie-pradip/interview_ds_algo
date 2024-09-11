/*
Leetcode Link               : https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
Leetcode difficulty         : Easy
Leetcode Related Topic      : Bit Manipulation
Medium Article Link	        : https://medium.com/@pradipalabade/2220-minimum-bit-flips-to-convert-number-87cd72497de7
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: XOR and Count Set Bits
//T.C       : O(log(n))
//S.C       : O(1)
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int xorVal=start^goal;
        int count=0;
        
        while(xorVal>0){
            if(xorVal&1){
                count++;
            }
            xorVal>>=1;
        }
        return count;
    }
};
//-------------------------------------------------------------------------------------------------------------
//Approach 2: Using built in function to count 1
//T.C       : O(1)
//S.C       : O(1)
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR the start and goal to find differing bits and use __builtin_popcount
        return __builtin_popcount(start ^ goal);
    }
};

//-------------------------------------------------------------------------------------------------------------
//Approach 3: Manual Bit Manipulation
//T.C       : O(log(n))
//S.C       : O(1)
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count=0;
        
        while(start>0 || goal>0){
            if((start&1) != (goal&1)){
                count++;
            }
            
            start>>=1;
            goal>>=1;
        }
        return count;
    }
};
//----------------------------------------------------------------------------------------------------------------


