/*
GFG Link               : https://www.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1
GFG Problem difficulty : Medium
GFG Related Topic      : Arrays Sorting

To solve the problem of counting triangles that can be formed using three different elements of an array, we need to apply the triangle inequality rule:
Triangle Inequality Rule:
For a triangle with sides a, b, and c (sorted such that a≤b≤c), it holds that:
            a+b>c
Given this rule, we can design various approaches to count all such valid triangles.
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1 : Brute Force
//T.C        : O(n^3)
//S.C        : O(1)
//-------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    int countTrianglesBruteForce(vector<int>& arr) {
        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (arr[i] + arr[j] > arr[k] && arr[j] + arr[k] > arr[i] && arr[k] + arr[i] > arr[j]) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
}
//--------------------------------------------------------------------------------------------------------------
//Approach 2 : Sorting + Two Pointer
//T.C        : O(n^2)
//S.C        : O(1)
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    int countTrianglesTwoPointer(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        sort(arr.begin(), arr.end());
        int count = 0;

        for (int k = 2; k < n; k++) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (arr[i] + arr[j] > arr[k]) {
                    count += (j - i); // All pairs from i to j-1 are valid
                    j--;
                } else {
                    i++;
                }
            }
        }

        return count;
    }
}
//------------------------------------------------------------------------------------------------------------------
//Approach 3 : Optimized Brute Force
//T.C        : O(n^2logn)
//S.C        : O(1)
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    int countTrianglesBinarySearch(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        sort(arr.begin(), arr.end());
        int count = 0;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int sum = arr[i] + arr[j];
                int k = lower_bound(arr.begin() + j + 1, arr.end(), sum) - arr.begin();
                count += (k - j - 1);
            }
        }

        return count;
    }
}
//------------------------------------------------------------------------------------------------------------------
