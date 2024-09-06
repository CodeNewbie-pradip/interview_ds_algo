/*
Leetcode Link               : https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Array     Linked List     Hash Table
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Using a Hash Set
//T.C       : O(n)
//S.C       : O(n)
//-------------------------------------------------------------------------------------------------------------

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        unordered_set<int>st(nums.begin(), nums.end());
        
        while(curr!=NULL && st.count(curr->val))
        {
            head=curr->next;
            curr=head;
        }
        
        while(curr!=NULL){
            int currVal=curr->val;
            if(!st.count(currVal)){
               prev=curr;
                curr=curr->next;
            }else{
                prev->next=curr->next;
                curr=curr->next;
            }
        }
        return head;
    }
};

//-------------------------------------------------------------------------------------------------------------
//Approach 2: Using a Hash Set for Efficient Lookup
//T.C       : O(nums.size())
//S.C       : O(nums.szie())
//-------------------------------------------------------------------------------------------------------------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        
        ListNode* curr=dummy;
        
        unordered_set<int>st(nums.begin(), nums.end());
        
        while(curr->next!=nullptr){
            if(st.count(curr->next->val)){
                curr->next=curr->next->next;
            }else{
                curr=curr->next;
            }
        }
        return dummy->next;
    }
};

//----------------------------------------------------------------------------------------------------