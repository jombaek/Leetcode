class Solution {
public:
    int jump(vector<int>& nums)
    {
        int n = nums.size();
        int end = 0, far = 0;
        int steps = 0;

        for (int i = 0; i < n - 1; ++i)
        {
            far = max(far, i + nums[i]);
            if (i == end)
            {
                end = far;
                steps++;
            }
            if (end >= n - 1)
                return steps;
        }

        return steps;
    }
};