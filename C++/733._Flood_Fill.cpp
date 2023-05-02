// BFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        int m = image.size();
        int n = image[0].size();
        int oldColor = image[sr][sc];
        queue<pair<int, int>> q;

        if (oldColor == color)
            return image;

        q.push({sr, sc});

        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            image[r][c] = color;

            if (r > 0 && image[r - 1][c] == oldColor)
                q.push({r - 1, c});
            if (r < m - 1 && image[r + 1][c] == oldColor)
                q.push({r + 1, c});
            if (c > 0 && image[r][c - 1] == oldColor)
                q.push({r, c - 1});
            if (c < n - 1 && image[r][c + 1] == oldColor)
                q.push({r, c + 1});
        }

        return image;
    }
};

// DFS
class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int color)
    {
        if (image[r][c] == oldColor)
        {
            image[r][c] = color;

            if (r > 0)
                dfs(image, r - 1, c, oldColor, color);
            if (r < image.size() - 1)
                dfs(image, r + 1, c, oldColor, color);
            if (c > 0)
                dfs(image, r, c - 1, oldColor, color);
            if (c < image[0].size() - 1)
                dfs(image, r, c + 1, oldColor, color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        int oldColor = image[sr][sc];

        if (oldColor != color)
            dfs(image, sr, sc, oldColor, color);
        
        return image;
    }
};