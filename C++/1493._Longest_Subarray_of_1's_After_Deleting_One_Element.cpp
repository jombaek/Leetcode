class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        int n = nums.size();
        int prevCount = 0;
        int count = 0;
        int res = 0;

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == 1)
                count++;
            else
            {
                res = max(res, prevCount + count);
                prevCount = count;
                count = 0;
            }

            res = max(res, prevCount + count);
        }

        return res == n ? res - 1 : res;
    }
};