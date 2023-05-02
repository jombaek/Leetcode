class Solution {
    #define ll long long
public:
    int chalkReplacer(vector<int>& chalk, int k)
    {
        ll l = 0;
        ll r = chalk.size() - 1;
        vector<ll> pSum(chalk.begin(), chalk.end());

        for (int i = 1; i < pSum.size(); ++i)
            pSum[i] += pSum[i - 1];

        k %= pSum.back();

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            
            if (pSum[mid] > k)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return l;
    }
};