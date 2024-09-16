/*
Leetcode Link               : https://leetcode.com/problems/minimum-time-difference/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Array Math String Sorting
Medium Article Link	        : https://medium.com/@pradipalabade/539-minimum-time-difference-e147ad648c09
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Brute Force
//T.C       : O(nlog(n))   Time Conversion:𝑂(𝑛), Sorting: 𝑂(𝑛log⁡𝑛), Finding Minimum Difference: 𝑂(𝑛).
//S.C       : O()
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
        int hh=0, mm=0;
        
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

//Approach 1 : 
//T.C        :
//S.C        :
//------------------------------------------------------------------------------------------------------------------
class Solution {
    public int timeDifferenceInMinutes(String time) {
        int hh = Integer.parseInt(time.substring(0, 2));
        int mm = Integer.parseInt(time.substring(3, 2));
        
        return hh * 60 + mm;
    }

    public int findMinDifference(List<String> timePoints) {
        int minDiff = Integer.MAX_VALUE;
        List<Integer> minutes = new ArrayList<>();
        
        for (String time : timePoints) {
            minutes.add(timeDifferenceInMinutes(time));
        }
        
        Collections.sort(minutes);
        
        for (int i = 1; i < minutes.size(); i++) {
            minDiff = Math.min(minDiff, minutes.get(i) - minutes.get(i - 1));
        }
        
        int circularDiff = 1440 - (minutes.get(minutes.size() - 1) - minutes.get(0));
        
        return Math.min(minDiff, circularDiff);
    }
}

//--------------------------------------------------------------------------------------------
