class Solution {
public:
    int arrangeCoins(int n)
    {
        long long l = 1;
        long long r = n;
        long long mid, cur;

        while (l < r)
        {
            mid = l + (r - l + 1) / 2;
            cur = mid * (mid + 1) / 2;

            if (cur <= n)
                l = mid;
            else
                r = mid - 1;
        }

        return l;
    }
};