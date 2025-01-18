/*
GFG Link      	       : https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1
GFG Problem difficulty : Easy
GFG Related Topic      : Linked List
*/

//------------------------------Solution - in - C++ ----------------------------------------------------------------
//Approach 1 : Iterative
//T.C        : O(n)
//S.C        : O(1)
//------------------------------------------------------------------------------------------------------------------
class Solution{
    public:
    Node* reverseIterative(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next; // Save the next node
            curr->next = prev;       // Reverse the link
            prev = curr;             // Move prev to current
            curr = next;             // Move curr to next
        }
        return prev; // New head of the reversed list
    }
};
//------------------------------------------------------------------------------------------------------------------
//Approach 2 : Recursive
//T.C        : O(n)
//S.C        : O(n)
//------------------------------------------------------------------------------------------------------------------
class Solution{
    public:
    Node* reverseRecursive(Node* head) {
        if (!head || !head->next) return head; // Base case
        Node* rest = reverseRecursive(head->next); // Reverse the rest
        head->next->next = head; // Connect current node to reversed list
        head->next = nullptr;    // Set the next of the current node to NULL
        return rest;             // Return the new head
    }
};
//------------------------------------------------------------------------------------------------------------------
//Approach 3 : Using a Stack
//T.C        : O(n)
//S.C        : O(n)
//------------------------------------------------------------------------------------------------------------------
class Solution{
    public:
    Node* reverseUsingStack(Node* head) {
        stack<Node*> s;
        Node* curr = head;

        // Push all nodes onto the stack
        while (curr) {
            s.push(curr);
            curr = curr->next;
        }

        // Pop nodes and rebuild the list
        if (s.empty()) return nullptr;
        head = s.top();
        s.pop();
        curr = head;

        while (!s.empty()) {
            curr->next = s.top();
            s.pop();
            curr = curr->next;
        }
        curr->next = nullptr;
        return head;
    }

}
//------------------------------------------------------------------------------------------------------------------
//Approach 4 : Array
//T.C        : O(n)
//S.C        : O(n)
//------------------------------------------------------------------------------------------------------------------
class Solution{
    public:
    Node* reverseUsingArray(Node* head) {
        vector<int> values;
        Node* curr = head;

        // Store values in the array
        while (curr) {
            values.push_back(curr->data);
            curr = curr->next;
        }

        // Reverse the list using the array
        curr = head;
        for (int i = values.size() - 1; i >= 0; i--) {
            curr->data = values[i];
            curr = curr->next;
        }

        return head;
    }
};
//----------------------------------------------------------------------------------------------------------------