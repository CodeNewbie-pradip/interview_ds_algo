//link : https://www.geeksforgeeks.org/problems/total-count2415/1

class Solution {
  public:
  int helper(int k, int num){
      int quo=(num/k);
      if(num%k==0){
          return quo;
      }else{
          return quo+1;
      }
  }
    int totalCount(int k, vector<int>& arr) {
        // code here
        int cnt=0;
        for(auto a:arr){
            cnt+=helper(k, a);
        }
        return cnt;
    }
};