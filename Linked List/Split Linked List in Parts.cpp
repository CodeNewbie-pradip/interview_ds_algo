/*
Leetcode Link               : https://leetcode.com/problems/split-linked-list-in-parts/
Leetcode difficulty         : Easy
Leetcode Related Topic      : Linked List
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Length Calculation and Splitting
//T.C       : O(n)
//S.C       : O(k)
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr=head;
        int totalLength=0;
        
        while(curr!=NULL)
        {
            totalLength++;
            curr=curr->next;
        }
        
        int partSize=totalLength/k;
        int remainder=totalLength%k;
        
        vector<ListNode*>result(k, NULL) ;
        
        curr=head;
        for(int i=0; i<k && curr !=NULL; i++)
        {
                result[i]=curr;
                int currPartSize=partSize+(remainder-->0?1:0);
            
                for(int j=1; j<currPartSize; j++)
                {
                    curr=curr->next;
                }
            
                ListNode* next=curr->next;
                curr->next=NULL;
                curr=next;
        }
        return result;
    }
};

//-----------------------------------------------------------------------------------------------------------------
//Approach 2: Length Calculation and Splitting
//T.C       : O(n)
//S.C       : O(k + recursive Depth)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = getLength(head);
        vector<ListNode*> result(k, nullptr);
        splitRecursive(head, result, 0, length, k);
        return result;
    }
    
private:
    int getLength(ListNode* head) {
        int length = 0;
        while (head != nullptr) {
            length++;
            head = head->next;
        }
        return length;
    }
    
    ListNode* splitRecursive(ListNode* head, vector<ListNode*>& result, int index, int length, int k) {
        if (index == k || head == nullptr) return nullptr;
        
        int partSize = length / k;
        if (index < length % k) partSize++;
        
        result[index] = head;
        for (int i = 0; i < partSize - 1; i++) {
            head = head->next;
        }
        ListNode* next = head->next;
        head->next = nullptr;
        
        return splitRecursive(next, result, index + 1, length, k);
    }
};

//-----------------------------------------------------------------------------------------------------------------
//Approach 3: Pre-allocation and Iterative Break
//T.C       : O(n)
//S.C       : O(k)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);
        ListNode* curr = head;
        int length = 0;
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }
        
        int partSize = length / k;
        int remainder = length % k;
        
        curr = head;
        for (int i = 0; i < k; ++i) {
            result[i] = curr;
            int currPartSize = partSize + (remainder-- > 0 ? 1 : 0);
            for (int j = 1; j < currPartSize && curr != nullptr; ++j) {
                curr = curr->next;
            }
            if (curr != nullptr) {
                ListNode* next = curr->next;
                curr->next = nullptr;
                curr = next;
            }
        }
        
        return result;
    }
};

//----------------------------------------------------------------------------------------------------------------------