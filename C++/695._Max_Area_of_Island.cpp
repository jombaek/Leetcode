// BFS
class Solution {
public:
    int bfs(vector<vector<int>>& grid, int r, int c)
    {
        int area = 0;
        queue<pair<int, int>> q;

        q.push({r, c});
        grid[r][c] = 0;

        while (!q.empty())
        {
            auto [nr, nc] = q.front();
            q.pop();
            area++;

            if (nr > 0 && grid[nr - 1][nc] == 1)
            {
                q.push({nr - 1, nc});
                grid[nr - 1][nc] = 0;
            }
            if (nr < grid.size() - 1 && grid[nr + 1][nc] == 1)
            {
                q.push({nr + 1, nc});
                grid[nr + 1][nc] = 0;
            }
            if (nc > 0 && grid[nr][nc - 1] == 1)
            {
                q.push({nr, nc - 1});
                grid[nr][nc - 1] = 0;
            }
            if (nc < grid[0].size() - 1 && grid[nr][nc + 1] == 1)
            {
                q.push({nr, nc + 1});
                grid[nr][nc + 1] = 0;
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;

        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (grid[r][c] == 1)
                    maxArea = max(maxArea, bfs(grid, r, c));


        return maxArea;
    }
};

// DFS
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != 1)
            return 0;

        grid[r][c] = 0;
        return 1 + dfs(grid, r - 1, c) + dfs(grid, r + 1, c) + dfs(grid, r, c - 1) + dfs(grid, r, c + 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;

        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (grid[r][c] == 1)
                    maxArea = max(maxArea, dfs(grid, r, c));


        return maxArea;
    }
};