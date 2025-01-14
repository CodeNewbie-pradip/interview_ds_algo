/*
LeetCode Link      	        : https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2025-01-14
LeetCode Problem difficulty : Medium
LeetCode Related Topic      : Array, Hash-Table, Bit-MAnipulation
*/

//------------------------------Solution - in - C++ ----------------------------------------------------------------
//Approach 1 : Brute Force
//T.C        : O(n^2)
//S.C        : O(1)
//------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n, 0);
    
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j <= i; ++j) {
                for (int k = 0; k <= i; ++k) {
                    if (A[j] == B[k]) {
                        count++;
                        break; // Avoid double counting
                    }
                }
            }
            C[i] = count;
        }
    
        return C;
    }
};
//------------------------------------------------------------------------------------------------------------------
//Approach 2 : Sets For Tracking
//T.C        : O(n^2)
//S.C        : O(n)
//------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        unordered_set<int>seenA, seenB;
        vector<int>C(n, 0);

        for(int i=0; i<n; i++){
            seenA.insert(A[i]);
            seenB.insert(B[i]);

            int count=0;
            for(auto x:seenA){
                if(seenB.count(x)){
                    count++;
                }
            }
            C[i]=count;
        }
        return C;
    }
};
//------------------------------------------------------------------------------------------------------------------
//Approach 3 : Frequency Array
//T.C        : O(n)
//S.C        : O(n)
//------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
         int n = A.size();
        vector<int> C(n, 0), freq(n + 1, 0);
        int commonCount = 0;

        for (int i = 0; i < n; ++i) {
            if (++freq[A[i]] == 2) commonCount++;
            if (++freq[B[i]] == 2) commonCount++;
            C[i] = commonCount;
        }

        return C;
    }
};
//------------------------------------------------------------------------------------------------------------------
//Approach 4 : Bit Manipulation
//T.C        : O(n)
//S.C        : O(1)
//------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n, 0);
        int seenA = 0, seenB = 0;

        for (int i = 0; i < n; ++i) {
            seenA |= (1 << (A[i] - 1));
            seenB |= (1 << (B[i] - 1));
            C[i] = __builtin_popcount(seenA & seenB);
        }

        return C;
    }
};
//------------------------------------------------------------------------------------------------------------------

