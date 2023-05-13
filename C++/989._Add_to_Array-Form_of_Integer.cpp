class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k)
    {
        int cur = k;
        int i = num.size();
        vector<int> ans;

        while (--i >= 0 || cur > 0)
        {
            if (i >= 0)
                cur += num[i];
            ans.push_back(cur % 10);
            cur /= 10;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k)
    {
        for (int i = num.size() - 1; i >= 0 && k > 0; --i)
        {
            num[i] += k;
            k = num[i] / 10;
            num[i] %= 10;
        }

        while (k > 0)
        {
            num.insert(num.begin(), k % 10);
            k /= 10;
        }

        return num;
    }
};