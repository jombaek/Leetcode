class Solution {
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;

        int prev = 0;
        int cur = 1;

        for (int i = 2; i <=n; ++i)
        {
            int res = prev + cur;
            prev = cur;
            cur = res;
        }

        return cur;
    }
};