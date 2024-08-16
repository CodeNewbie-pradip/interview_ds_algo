/*
Leetcode Link               : https://leetcode.com/problems/maximum-distance-in-arrays/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Array, Greedy
*/

//------------------------------Solution - in - C++ ---------------------------------------------------------------------------

//Approach 1:Brute force
//T.C       :O(m^2)  &  S.C   :O(1)
//Error     :TLE
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int result=0;
        
        for(int i=0; i<arrays.size(); i++){
            for(int j=i+1; j<arrays.size(); j++){
                int dist1=abs(arrays[i].back()-arrays[j].front());
                int dist2=abs(arrays[j].back()-arrays[i].front());
                
                result=max(result, max(dist1,dist2));
            }
        }
        return result;
    }
};
//Approach 1:Optimized Pair Comparison
//T.C       :O(m)  &  S.C     :O(1)
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int max_Val=arrays[0].back();
        int min_Val=arrays[0].front();
        
        int max_dist=0;
        
        for(int i=1; i<arrays.size(); i++){
            max_dist=max(max_dist, abs(max_Val-arrays[i].front()));
            max_dist=max(max_dist, abs(arrays[i].back()-min_Val));
            min_Val=min(min_Val, arrays[i].front());
            max_Val=max(max_Val, arrays[i].back());
        }
        return max_dist;
    }
};
//Approach 3:Min-Max(Greedy Approach)
//T.C       :O(m)  &  S.C     :O(1)
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int Maxi=arrays[0].back();//max element in back of the array
        int Mini=arrays[0].front();//min element in front of the array
        
        int result=0;
        
        for(int i=1; i<arrays.size(); i++){
            int currMaxi=arrays[i].back();
            int currMini=arrays[i].front();
            
            result=max(result, max(abs(Mini-currMaxi), abs(Maxi-currMini)));
            
            Maxi=max(Maxi, currMaxi);
            Mini=min(Mini, currMini);
        }
        return result;
    }
};