class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        vector<int> dir = {-1, 0, 1, 0, -1};
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 2)
                    q.emplace(i, j);
                else if (grid[i][j] == 1)
                    ++fresh;
            }
        }

        int ans = -1;

        while (!q.empty())
        {
            int sz = q.size();

            while(sz--)
            {
                auto [r, c] = q.front();
                q.pop();

                for (int i = 0; i < 4; ++i)
                {
                    int nr = r + dir[i];
                    int nc = c + dir[i + 1];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1)
                    {
                        grid[nr][nc] = 2;
                        q.emplace(nr, nc);
                        --fresh;
                    }
                }
            }

            ++ans;
        }

        if (fresh > 0)
            return -1;
        
        return ans == -1 ? 0 : ans;
    }
};