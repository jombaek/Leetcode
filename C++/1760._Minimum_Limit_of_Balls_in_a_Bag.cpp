class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations)
    {
        int l = 1, r = 1e9;

        while (l < r)
        {
            int mid = (l + r) / 2;
            int count = 0;

            for (const auto& num : nums)
                count += (num - 1) / mid;

            if (count <= maxOperations)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};