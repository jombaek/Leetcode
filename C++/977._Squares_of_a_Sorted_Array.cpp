class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> res(n);

        int l = 0;
        int r = n - 1;
        int k = n - 1;

        while (l <= r)
        {
            if (abs(nums[l]) < abs(nums[r]))
                res[k--] = nums[r] * nums[r--];
            else
                res[k--] = nums[l] * nums[l++];
        }

        return res;
    }
};