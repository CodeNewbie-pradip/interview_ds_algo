/*
Leetcode Link           : 
Leetcode difficulty     : Easy
Leetcode Related Topic  : 
Medium Article Link	    : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Naive Approach
//T.C       :push O(1), pop(1), Increment O(k)
//S.C       : O(Maxsize)
//-----------------------------------------------------------------------------------------------------------------
class CustomStack {
public:
    int n;
    vector<int>st;
    CustomStack(int maxSize) {
        n=maxSize;
    }
    
    void push(int x) {
        if(st.size()<n){
            st.push_back(x);
        }
    }
    
    int pop() {
        if(st.size()>0){
            int top=st.back();
            st.pop_back();
            return top;
        }else{
            return -1;
        }
    }
    
    void increment(int k, int val) {
        for(int i=0; i< min(k, (int)st.size()); i++){
            st[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
//-----------------------------------------------------------------------------------------------------------------
//Approach 2: Optimized Lazy Increment
//T.C       : push O(1), Pop(1), Increment(1)
//S.C       : O(maxSize)
//-----------------------------------------------------------------------------------------------------------------
class CustomStack {
    vector<int> stack;
    vector<int> increment;  // Auxiliary array to store lazy increments
    int maxSize;

public:
    CustomStack(int maxSize) : maxSize(maxSize), increment(maxSize, 0) {}

    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }

    int pop() {
        if (stack.empty()) {
            return -1;
        }
        
        int idx = stack.size() - 1;
        int val = stack.back() + increment[idx];  // Apply lazy increment
        if (idx > 0) {
            increment[idx - 1] += increment[idx];  // Propagate increment to the next element
        }
        increment[idx] = 0;  // Reset increment for this element
        stack.pop_back();
        return val;
    }

    void increment(int k, int val) {
        int limit = min(k, (int)stack.size());
        if (limit > 0) {
            increment[limit - 1] += val;  // Store increment for the bottom `limit` elements
        }
    }
};
//-----------------------------------------------------------------------------------------------------------------

