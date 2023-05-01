class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int n = nums.size();
        int l = 0, r = 0;
        int sum = 0, minLen = INT_MAX;

        while (r < n)
        {
            sum += nums[r++];

            while (sum >= target)
            {
                minLen = min(minLen, r - l);
                sum -= nums[l++];
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};