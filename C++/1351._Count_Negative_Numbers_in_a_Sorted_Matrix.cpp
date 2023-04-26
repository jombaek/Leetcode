class Solution {
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; ++i)
        {
            int l = 0;
            int r = n - 1;

            while (l < r)
            {
                int mid = l + (r - l) / 2;

                if (grid[i][mid] < 0)
                    r = mid;
                else
                    l = mid + 1;
            }

            count += (grid[i][l] < 0 ? n - l : 0);
        }

        return count;
    }
};