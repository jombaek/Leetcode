class Solution {
public:
    vector<string> ans;

    void backtrack(string& s, vector<string>& ans, int i)
    {
        if (i == s.size())
        {
            ans.push_back(s);
            return;
        }

        if (isalpha(s[i]))
        {
            s[i] = toupper(s[i]);
            backtrack(s, ans, i + 1);
            s[i] = tolower(s[i]);
            backtrack(s, ans, i + 1);
        }
        else
            backtrack(s, ans, i + 1);
    }

    vector<string> letterCasePermutation(string s)
    {
        backtrack(s, ans, 0);

        return ans;
    }
};