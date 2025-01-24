/*
GFG Link      	       : 
GFG Problem difficulty : 
GFG Related Topic      : 
*/
//------------------------------Solution - in - C++ ---------------------------------------------------------------
//Approach 1 : Hashing
//T.C        : O(n)
//S.C        : O(n)
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        if(!head || !head->next){
            return false;
        unordered_set<ListNode*> visited;
        ListNode* current = head;
    
        while (current) {
            if (visited.find(current) != visited.end()) {
                return true; // Loop detected
            }
            visited.insert(current);
            current = current->next;
        }
        return false; // No loop
    }
};
//------------------------------------------------------------------------------------------------------------------
//Approach 2 : Floyd's Algorithm
//T.C        : O(1)
//S.C        : O(1)
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        if(!head || !head->next){
            return false;
        }
        
        Node* slow=head;
        Node* fast=head;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) return true;
        }
        return false;
    }
};
//------------------------------------------------------------------------------------------------------------------
//Approach 3 : Marking Visited Nodes
//T.C        : O(n)
//S.C        : O(1)
//------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        ListNode* marker = head;

    while (head) {
        if (head->next == marker) return true; // Loop detected
        ListNode* temp = head->next;
        head->next = marker; // Mark the node as visited
        head = temp;
    }
    return false; // No loop
    }
};
//------------------------------------------------------------------------------------------------------------------
