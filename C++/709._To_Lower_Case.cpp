class Solution {
public:
    string toLowerCase(string s)
    {
        for (auto& c : s)
        {
            if (c <= 'Z' && c >= 'A')
                c += 32;
        }

        return s;
    }
};