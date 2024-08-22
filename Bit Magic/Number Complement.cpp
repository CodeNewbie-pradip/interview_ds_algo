/*
Leetcode Link               : https://leetcode.com/problems/number-complement/
Leetcode difficulty         : Easy
Leetcode Related Topic      : Bit Manipulation
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1:Subtract from the Next Power of Two
//T.C       : O(log(num))
//S.C       : O(1)
//Error     : TLE
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int findComplement(int num) {
        int powerOfTwo = 1;
    while (powerOfTwo <= num) {
        powerOfTwo <<= 1;
    }
    
    return powerOfTwo - 1 - num;
    }
};

//---------------------------------------------------------------------------------------------------------------
//Approach 2:Using the inbuilt function
//T.C       : O(1)
//S.C       : O(1)
//---------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int findComplement(int num) {
        string binary=bitset<32>(num).to_string();
        size_t pos=binary.find('1');//find whee starts from bit otherwise previos 0 bin flip so anwer will give wrong
        
        for(size_t i=pos; i<binary.size(); i++){
            binary[i]=(binary[i]=='1')?'0':'1';//flip the bits;
        }
        return stoi(binary.substr(pos), NULL, 2);//convert to bin tointeger
    }
};

//---------------------------------------------------------------------------------------------------------------
//Approach 3: Bit Manipulation
//T.C       : O(1)
//S.C       : O(1)
//---------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int findComplement(int num) {
        // Initialize mask to the first number greater than num with all bits set to 1
    int mask = num;
    // Create a mask with all bits set to 1
    mask |= (mask >> 1);
    mask |= (mask >> 2);
    mask |= (mask >> 4);
    mask |= (mask >> 8);
    mask |= (mask >> 16);
    
    // XOR num with the mask to get the complement
    return num ^ mask;
    }
};

//----------------------------------------------------------------------------------------------------------------