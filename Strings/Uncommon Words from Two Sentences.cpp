/*
Leetcode Link               : https://leetcode.com/problems/uncommon-words-from-two-sentences/
Leetcode difficulty         : Easy
Leetcode Related Topic      : String, Hash table Counting
Medium Article Link	        : https://medium.com/@pradipalabade/884-uncommon-words-from-two-sentences-becaf5bdb48d
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Brute force
//T.C       : O(m+n) spliting or counting
//S.C       : O(k) frequency of map
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int timeDifferenceInMinutes(string & time){
        int hh=stoi(time.substr(0, 2));
        int mm=stoi(time.substr(3, 2));
        
        return hh*60+mm;
    }
    int findMinDifference(vector<string>& timePoints) {
        int minDiff=INT_MAX;
        
        vector<int>minutes;
        
        for(auto time:timePoints){
            minutes.push_back(timeDifferenceInMinutes(time));
        }
        
        sort(minutes.begin(), minutes.end());
        
        for(int i=1; i<minutes.size(); i++){
            minDiff=min(minDiff, minutes[i]-minutes[i-1]);
        }
        
        int circularDiff=1440-(minutes.back()-minutes[0]);
        
        return min(minDiff, circularDiff);
    }
};
//-----------------------------------------------------------------------------------------------------------------
//------------------------------Solution - in - Java -----------------------------------------------------------

//Approach 1   : Brute force
//T.C          : O(n)
//S.C          : O(1)
//------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------------