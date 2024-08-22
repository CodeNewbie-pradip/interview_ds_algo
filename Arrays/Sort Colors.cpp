/*
Leetcode Link               : https://leetcode.com/problems/sort-colors/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Array, Two Pointer, Sorting
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1:Counting Sort (Two-pass Algorithm)
//T.C       : O(1)
//S.C       : O(1)
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0=0;
        int count1=0;
        int count2=0;
        for(auto num:nums){
            if(num==0){
                count0++;
            }else if(num==1){
                count1++;
            }else{
                count2++;
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(count0>0){
                nums[i]=0;
                count0--;
            }else if(count1>0){
                nums[i]=1;
                count1--;
            }else{
                nums[i]=2;
            }
        }
    }
};

//-----------------------------------------------------------------------------------------------------------

//Approach 2: Dutch National Flag
//T.C       : O(1)
//S.C       : O(1)
//-------------------------------------------------------------------------------------------------------------

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, mid=0, high=nums.size()-1;
        
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid], nums[high]);
                high--;
            }
            else
            {
                mid++;
            }
        }
    }
};

//----------------------------------------------------------------------------------------------------------
//Approach 3: Approach 3: Two-pointer Approach with Two-pass (Partitioning)
//T.C       :O(1)
//S.C       :O(1)
//-----------------------------------------------------------------------------------------------------------

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
    
    for (int i = 0; i <= high;) {
        if (nums[i] == 0) {
            swap(nums[i], nums[low]);
            low++;
            i++;
        } else if (nums[i] == 2) {
            swap(nums[i], nums[high]);
            high--;
        } else {
            i++;
        }
        }
    }
};

//----------------------------------------------------------------------------------------------------------
//Approach 4: Modified Bubble Sort
//T.C       :O(N^2)
//S.C       :O(1)
//-----------------------------------------------------------------------------------------------------------

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n-1-i; j++){
                if(nums[j]>nums[j+1]){
                    swap(nums[j], nums[j+1]);
                }
            }
        }
    }
};

//---------------------------------------------------------------------------------------------------------