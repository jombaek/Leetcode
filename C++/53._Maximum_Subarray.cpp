class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int n = nums.size();
        int maxSum = nums[0];
        int curSum = nums[0];

        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > curSum + nums[i])
                curSum = nums[i];
            else
                curSum += nums[i];
            
            if (curSum > maxSum)
                maxSum = curSum;
        }

        return maxSum;
    }
};