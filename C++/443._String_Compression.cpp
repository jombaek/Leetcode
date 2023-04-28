class Solution {
public:
    int compress(vector<char>& chars)
    {
        int n = chars.size();
        int i = 0, res = 0;

        while (i < n)
        {
            int groupLength = 1;

            while (i + groupLength < n && chars[i + groupLength] == chars[i])
                groupLength++;
            
            chars[res++] = chars[i];

            if (groupLength > 1)
            {
                for (char c : to_string(groupLength))
                    chars[res++] = c;
            }

            i += groupLength;
        }

        return res;
    }
};