class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr)
    {
        int n = arr.size();
        int sum = 0;

        for (int l = 0; l < n; ++l)
        {
            int curSum = 0;

            for (int r = l; r < n; ++r)
            {
                curSum += arr[r];
                sum += (r - l + 1) % 2 == 1 ? curSum : 0;
            }
        }

        return sum;
    }
};