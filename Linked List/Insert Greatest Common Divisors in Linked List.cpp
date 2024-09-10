/*
Leetcode Link               : https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Linked List, Number Theory, Math
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Iterative Approach with GCD Calculation
//T.C       : O(n)
//S.C       : O(1)
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    
    int gcd(int a, int b){
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
     if(head==NULL || head->next==NULL){
         return head;
     }   
        
        ListNode* curr=head;
        
        while(curr && curr->next){
            int gcdVal=gcd(curr->val, curr->next->val);
            ListNode* newNode=new ListNode(gcdVal);
            newNode->next=curr->next;
            curr->next=newNode;
            curr=newNode->next;
        }
        
        return head;
    }
};
//-------------------------------------------------------------------------------------------------------------
//Approach 2: Recursive Approach
//T.C       : O(n)
//S.C       : O(n)
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    
    int gcd(int a, int b){
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
     if (!head || !head->next) return head;
        
        // Recursive case: get the next node after recursion
        head->next = insertGreatestCommonDivisors(head->next);
        
        // Calculate the GCD of current node and next node
        int gcdVal = gcd(head->val, head->next->val);
        
        // Create a new node with the GCD value
        ListNode* gcdNode = new ListNode(gcdVal);
        
        // Insert the new node between the current and next node
        gcdNode->next = head->next;
        head->next = gcdNode;
        
        return head;
    }
};
//-----------------------------------------------------------------------------------