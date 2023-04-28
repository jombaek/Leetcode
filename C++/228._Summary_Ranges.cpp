class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        int n = nums.size();
        vector<string> res;

        if (n == 0)
            return {};

        int start = nums[0], end = nums[0];

        for (int i = 1; i < n; ++i)
        {
            if (nums[i] == end + 1)
                end = nums[i];
            else
            {
                if (start == end)
                    res.push_back(to_string(start));
                else
                {
                    string tmp = "";
                    tmp += to_string(start);
                    tmp += "->";
                    tmp += to_string(end);
                    res.push_back(tmp);
                }

                start = end = nums[i];
            }
        }

        if (start == end)
            res.push_back(to_string(start));
        else
        {
            string tmp = "";
            tmp += to_string(start);
            tmp += "->";
            tmp += to_string(end);
            res.push_back(tmp);
        }

        return res;
    }
};