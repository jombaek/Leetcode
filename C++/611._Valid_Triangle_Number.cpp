class Solution {
public:
    int binarySearch(vector<int>& nums, int l, int r, int x)
    {
        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] >= x)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return l;
    }

    int triangleNumber(vector<int>& nums)
    {
        int n = nums.size();
        int count = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i)
        {
            int k = i + 2;

            for (int j = i + 1; j < n - 1 && nums[i] != 0; ++j)
            {
                k = binarySearch(nums, k, n - 1, nums[i] + nums[j]);
                count += k - j - 1;
            }
        }

        return count;
    }
};