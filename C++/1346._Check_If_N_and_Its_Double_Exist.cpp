class Solution {
public:
    bool checkIfExist(vector<int>& arr)
    {
        int n = arr.size();
        int zeroCount = 0;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; ++i)
        {
            int l = 0;
            int r = n - 1;
            int doubleValue = 2 * arr[i];

            if (arr[i] != 0)
            {
                while (l <= r)
                {
                    int mid = l + (r - l) / 2;
                    
                    if (arr[mid] > doubleValue)
                        r = mid - 1;
                    else if (arr[mid] < doubleValue)
                        l = mid + 1;
                    else
                        return true;
                }
            }
            else
                zeroCount++;
        }

        return zeroCount >= 2;
    }
};