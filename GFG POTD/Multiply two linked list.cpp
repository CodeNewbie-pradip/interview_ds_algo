/*
GFG Link               : https://www.geeksforgeeks.org/problems/multiply-two-linked-lists/1
GFG Problem difficulty : EASY
GFG Related Topic      : Linked List, Modular Arithmetic, DSA structure, Algotihms
Medium Article Link    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1 : convert linked list into number
//T.C        : O(n+m)
//S.C        : O(1)
//------------------------------------------------------------------------------------------------------------------
class solution {
  public:
  //long long mod=1000000007;
  long long MOD=1000000007;
  long long giveNumber(Node* head){
      long long num=0;
      while(head!=NULL){
          num=(num*10 + head->data)%MOD;
          head=head->next;
      }
      return num;
  }
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long num1=0, num2=0;
        num1=giveNumber(first);
        num2=giveNumber(second);
        
        return (num1*num2)%MOD;
    }
};
//------------------------------------------------------------------------------------------------------------------