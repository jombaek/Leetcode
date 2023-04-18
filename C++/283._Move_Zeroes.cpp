class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int n = nums.size();
        int k = 0;

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == 0)
            {
                k++;
                continue;
            }

            nums[i - k] = nums[i];
        }

        int i = n - 1;
        while (k--)
        {
            nums[i--] = 0;
        }
    }
};