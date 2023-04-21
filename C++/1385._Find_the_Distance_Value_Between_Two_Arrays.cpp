class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d)
    {
        int n = arr1.size();
        int m = arr2.size();
        int count = 0;
        sort(arr2.begin(), arr2.end());

        for (int i = 0; i < n; ++i)
        {
            int l = 0;
            int r = m;
            bool isValid = true;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;

                if (abs(arr1[i] - arr2[mid]) <= d)
                {
                    isValid = false;
                    break;
                }
                else if (arr1[i] < arr2[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }

            if (isValid)
                ++count;
        }

        return count;
    }
};