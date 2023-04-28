class Solution {
public:
    bool isValid(string s)
    {
        int n = s.size();
        stack<char> par;

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                par.push(s[i]);
            else if (!par.empty() && s[i] == ')' && par.top() == '(')
                par.pop();
            else if (!par.empty() && s[i] == '}' && par.top() == '{')
                par.pop();
            else if (!par.empty() && s[i] == ']' && par.top() == '[')
                par.pop();
            else
                return false;
        }

        return par.empty() ? true : false;
    }
};