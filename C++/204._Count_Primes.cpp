class Solution {
public:
    int countPrimes(int n)
    {
        vector<bool> seen(n, false);
        int j, count = 0;

        for (int i = 2; i < n; ++i)
        {
            if (!seen[i])
            {
                count++;
                j = i + i;

                while (j < n)
                {
                    seen[j] = true;
                    j += i;
                }
            }
        }

        return count;
    }
};