class Solution {
public:
    string freqAlphabets(string s)
    {
        string ans;
        int n = s.size();
        int i = 0;

        while (i < n)
        {
            if (i + 2 < n && s[i + 2] == '#')
            {
                ans += (s[i] - '0') * 10 + (s[i + 1] - '0') - 1 + 'a';
                i += 3;
            }
            else
            {
                ans += s[i] - '0' - 1 + 'a';
                ++i;
            }
        }

        return ans;
    }
};