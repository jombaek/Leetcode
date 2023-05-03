class Solution {
public:
    char findTheDifference(string s, string t)
    {
        char ans = 0;

        for (const auto& c : s)
            ans ^= c;
        
        for (const auto& c : t)
            ans ^= c;

        return ans;
    }
};