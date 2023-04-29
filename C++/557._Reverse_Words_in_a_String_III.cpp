class Solution {
public:
    string reverseWords(string s)
    {
        int n = s.size();
        int l = 0, r;

        for (int i = 0; i <= n; ++i)
        {
            if (s[i] == ' ' || i == n)
            {
                r = i - 1;

                while (l < r)
                {
                    swap(s[l++], s[r--]);
                }

                l = i + 1;
            }
        }

        return s;
    }
};