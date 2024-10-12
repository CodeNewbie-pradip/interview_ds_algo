/*
Leetcode Link           : https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/
Leetcode difficulty     : Medium
Leetcode Related Topic  : Array,Two Pinter, Greedy, Sorting, Heap(Priority Queue) Prefix Sum.
Medium Article Link	    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Using Interval Merging
//T.C       : O(nlogn)
//S.C       : O(n)
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        priority_queue<int, vector<int>, greater<int>>minHeap;
        
        for(auto interval:intervals){
            if(!minHeap.empty() && interval[0]>minHeap.top()){
                minHeap.pop();
            }
            minHeap.push(interval[1]);
        }
        return minHeap.size();
    }
};
//--------------------------------------------------------------------------------------------------------------