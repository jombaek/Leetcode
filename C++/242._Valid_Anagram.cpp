class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> mp1, mp2;
        
        for (int i = 0; i < s.size(); ++i)
        {
            mp1[s[i]]++;
        }

        for (int i = 0; i < t.size(); ++i)
        {
            mp2[t[i]]++;
        }

        return mp1 == mp2;
    }
};