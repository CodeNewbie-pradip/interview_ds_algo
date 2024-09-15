/*
Leetcode Link               : https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
Leetcode difficulty         : medium
Leetcode Related Topic      : Hash Table, String, Bit-Manipulation, Prefix sum
Medium Article Link	        : 
*/

//------------------------------Solution - in - C++ --------------------------------------------------------------
//Approach 1: Prefix XOR with State Masking
//T.C       : O(n)
//S.C       : O(1)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int>mp;
        int mask=0;
        mp[0]=-1;
        int max_len=0;
    
        for (int i = 0; i < s.length(); ++i) 
        {
            if (s[i] == 'a') mask^=(1<<0);
            else if (s[i] == 'e') mask^=(1<<1);
            else if (s[i] == 'i') mask^=(1<<2);
            else if (s[i] == 'o') mask^=(1<<3);
            else if (s[i] == 'u') mask^=(1<<4);
            
            if(mp.find(mask)!=mp.end())
            {
                max_len=max(max_len, i-mp[mask]);
            }else
            {
                mp[mask]=i;
            }
        }
        
        return max_len;       
    }
};
//-----------------------------------------------------------------------------------------------------------------
//------------------------------Solution - in - Java --------------------------------------------------------------
//Approach 1 : Prefix XOR with State Masking
//T.C        : O(n)
//S.C        : O(1)
//------------------------------------------------------------------------------------------------------------------

public class Solution {
    public int findTheLongestSubstring(String s) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int mask = 0;
        map.put(0, -1);
        int maxLen = 0;

        for (int i = 0; i < s.length(); ++i) {
            char ch = s.charAt(i);
            if (ch == 'a') mask ^= (1 << 0);
            else if (ch == 'e') mask ^= (1 << 1);
            else if (ch == 'i') mask ^= (1 << 2);
            else if (ch == 'o') mask ^= (1 << 3);
            else if (ch == 'u') mask ^= (1 << 4);

            if (map.containsKey(mask)) {
                maxLen = Math.max(maxLen, i - map.get(mask));
            } else {
                map.put(mask, i);
            }
        }

        return maxLen;
    }
}

//------------------------------------------------------------------------------------------------------------------
