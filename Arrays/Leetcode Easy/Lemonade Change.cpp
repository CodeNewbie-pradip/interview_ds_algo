/*
Leetcode Link               : https://leetcode.com/problems/lemonade-change
Leetcode difficulty         : Easy
Leetcode Related Topic      : Array, Greedy
*/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveDollar = 0;
        int tenDollar = 0;
        
        for(auto bill : bills) {
            if(bill == 5) {
                fiveDollar++;
            } else if(bill == 10 && fiveDollar > 0) {
                fiveDollar--;
                tenDollar++;
            } else if(tenDollar > 0 && fiveDollar > 0) { // when returning 15 dollars
                tenDollar--; 
                fiveDollar--;
            } else if(fiveDollar >= 3) {
                fiveDollar -= 3;
            } else {
                return false;
            }
        }
        return true;
    }
};
