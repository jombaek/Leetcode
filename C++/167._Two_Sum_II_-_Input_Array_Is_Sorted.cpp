class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int n = numbers.size();

        for (int i = 0; i < n; ++i)
        {
            int l = i + 1;
            int r = n - 1;

            while (l < r)
            {
                int mid = l + (r - l) / 2;

                if (numbers[i] + numbers[mid] >= target)
                    r = mid;
                else
                    l = mid + 1;
            }

            if (numbers[i] + numbers[l] == target)
                return {i + 1, l + 1};
        }

        return {};
    }
};