class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> uset;
        int n = s.size();
        int l = 0, r = 0, maxLen = 0;

        while (l < n && r < n)
        {
            if (!uset.count(s[r]))
            {
                uset.insert(s[r++]);
                maxLen = max(maxLen, r - l);
            }
            else
            {
                uset.erase(s[l++]);
            }
        }

        return maxLen;
    }
};