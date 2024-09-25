GeeksforGeeks
/*
GFG Link      	       : https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
GFG Problem difficulty : Medium
GFG Related Topic      : Linked List, Palindrome, Data Structures
Medium Article Link    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1 : Using a stack(Extra Space)
//T.C        : O(n)
//S.C        : O(n) stack stores half of the linked list
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        Node* curr=head;
        Node* slow=curr;
        Node* fast=curr;
        stack<int>st;
        
        while(fast!=NULL && fast->next!=NULL){
            st.push(slow->data);
            slow=slow->next;
            fast=fast->next->next;
        }
        
        if(fast!=NULL){
            slow=slow->next;
        }
        while(slow!=NULL){
            if(st.top()!=slow->data){
            return false;
            }
            st.pop();
            slow=slow->next;
        }
        return true;
    }
};
//------------------------------------------------------------------------------------------------------------------