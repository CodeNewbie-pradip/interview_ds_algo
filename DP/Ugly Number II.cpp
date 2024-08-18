/*
Leetcode Link               : https://leetcode.com/problems/ugly-number-ii/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Hash Table, Math, Dynamic Programing, Heap(Priority Queue)
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1:Using set
//T.C       :O(n log m)  &  S.C   :O(n^2)

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> uglyNumbersSet;  // Set to store potential ugly numbers
        uglyNumbersSet.insert(1);  // Start with 1, the first ugly number

        long currentUgly = 1;
        for (int i = 0; i < n; i++) {
            currentUgly =*uglyNumbersSet.begin();  // Get the smallest number from the set
            uglyNumbersSet.erase(uglyNumbersSet.begin());  // Remove it from the set

            // Insert the next potential ugly numbers
            uglyNumbersSet.insert(currentUgly * 2);
            uglyNumbersSet.insert(currentUgly * 3);
            uglyNumbersSet.insert(currentUgly * 5);
        }

        return static_cast<int>(currentUgly);  // Return the nth ugly number
    }
};

//-----------------------------------------------------------------------------------
//Approach 2:Min Heap
//T.C       :O(nlogn)  &  S.C   :O(m) ->space is used by minheap,set

class Solution {
public:
    int nthUglyNumber(int n) {
        // Min-heap to store and retrieve the smallest ugly number
        priority_queue<long, vector<long>, greater<long>> minHeap;
        unordered_set<long> seenNumbers;  // Set to avoid duplicates
        vector<int> primeFactors = {
            2, 3, 5};  // Factors for generating new ugly numbers

        minHeap.push(1);
        seenNumbers.insert(1);

        long currentUgly = 1;
        for (int i = 0; i < n; ++i) {
            currentUgly = minHeap.top();  // Get the smallest number
            minHeap.pop();                // Remove it from the heap

            // Generate and push the next ugly numbers
            for (int prime : primeFactors) {
                long nextUgly = currentUgly * prime;
                if (seenNumbers.find(nextUgly) ==
                    seenNumbers.end()) {  // Avoid duplicates
                    minHeap.push(nextUgly);
                    seenNumbers.insert(nextUgly);
                }
            }
        }

        return static_cast<int>(currentUgly);  // Return the nth ugly number
    }
};
//-----------------------------------------------------------------------------------

//Approach 3:Bottom - Up Dynamic Programming
//T.C       :O(n)  &  S.C   :O(n)

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>ugly(n);
        ugly[0]=1;
        int p2=0, p3=0, p5=0;
        
        for(int i=1; i<n; i++){
            ugly[i]=min(ugly[p2]*2, min(ugly[p3]*3, ugly[p5]*5));
            
            if(ugly[i]==ugly[p2]*2){
                p2++;
            }if(ugly[i]==ugly[p3]*3){
                p3++;
            }if(ugly[i]==ugly[p5]*5){
                p5++;
            }
        }
        return ugly[n-1];
    }
};