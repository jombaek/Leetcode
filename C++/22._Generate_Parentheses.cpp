class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        addingpar(res, "", n, 0);

        return res;
    }

    void addingpar(vector<string>& v, string s, int n, int m)
    {
        if(n == 0 && m == 0)
        {
            v.push_back(s);
            return;
        }

        if (n > 0)
            addingpar(v, s + "(", n - 1, m + 1);

        if (m > 0)
            addingpar(v, s + ")", n, m - 1);
    }
};