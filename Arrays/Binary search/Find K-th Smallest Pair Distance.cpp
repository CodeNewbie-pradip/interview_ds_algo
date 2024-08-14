/*    Leetcode Link               : https://leetcode.com/problems/find-k-th-smallest-pair-distance
*/


/******************************************************************** C++ **********************************************************************/
//Approach-1 (Brute force approach)
//T.C : 𝑂(𝑛^2log𝑛)
//S.C : O(maxEl)
//it shows TLE

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> distances;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            distances.push_back(abs(nums[i] - nums[j]));
        }
    }
    sort(distances.begin(), distances.end());
    return distances[k - 1];
    }
};
------------------------------------------------------------------
//Approach-2 (storing the distances and finding the kth smallest)
//T.C : O(n^2)
//S.C : O(maxEl)
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
         int n=nums.size();
         int maxEl=*max_element(begin(nums), end(nums));
        
         vector<int>result(maxEl+1, 0);
        
         for(int i=0; i<n; i++){
             for(int j=i+1; j<n; j++){
                 int d=abs(nums[i]-nums[j]);
                 result[d]++;
             }
         }
         for(int i=0; i<=maxEl; i++){
             k-=result[i];
             if(k<=0){
                 return i;
             }
         }
         return -1;
    }
};

