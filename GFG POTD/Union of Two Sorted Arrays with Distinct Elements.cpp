/*
GFG Link               : https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-with-distinct-elements/1
GFG Problem difficulty : Easy
GFG Related Topic      : Array, set, 2 Pointers
Medium Article Link    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1 : using 2-Pointer Technique 
//T.C        : O(n+m)
//S.C        : O(n+m)
//--------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        vector<int>result;
        int i=0, j=0, m=a.size(), n=b.size();
        
        while(i<m && j<n){
            if(a[i]<b[j]){
                result.push_back(a[i++]);
            }
            else if(a[i]>b[j]){
                result.push_back(b[j++]);
            }
            else{
                result.push_back(a[i]); 
                i++;
                j++;  
            }
        }
        
        while(i<m){
            result.push_back(a[i++]);
        }
        
        while(j<n){
            result.push_back(b[j++]);
        }
        
        return result;
    }
};
//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------
//Approach 2 : Using set DS
//T.C        : O(m+n)log(m+n)
//S.C        : O(m+n)
//--------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        set<int>st;
        for(auto num:a){
            st.insert(num);
        }
        for(auto num:b){
            st.insert(num);
        }
        
        vector<int>uni(st.begin(), st.end());
        
        return uni;
    }
};
//--------------------------------------------------------------------------------------------------------------
//Approach 3 : Using Merge & Sort
//T.C        : O(m+n)log(m+n)
//S.C        : O(m+n)log(m+n)
//--------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        vector<int>merged=a;
        merged.insert(merged.end(), b.begin(), b.end());
        
        //sort the merged array
        sort(merged.begin(), merged.end());
        merged.erase(unique(merged.begin(), merged.end()), merged.end());
        
        return merged;
    }
};
//--------------------------------------------------------------------------------------------------------------
