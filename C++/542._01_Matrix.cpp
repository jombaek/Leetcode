class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][j] == 0)
                    q.emplace(i, j);
                else
                    mat[i][j] = -1;
            }
        }

        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            if (r > 0 && mat[r - 1][c] == -1)
            {
                mat[r - 1][c] = mat[r][c] + 1;
                q.emplace(r - 1, c);
            }
            if (r < m - 1 && mat[r + 1][c] == -1)
            {
                mat[r + 1][c] = mat[r][c] + 1;
                q.emplace(r + 1, c);
            }
            if (c > 0 && mat[r][c - 1] == -1)
            {
                mat[r][c - 1] = mat[r][c] + 1;
                q.emplace(r, c - 1);
            }
            if (c < n - 1 && mat[r][c + 1] == -1)
            {
                mat[r][c + 1] = mat[r][c] + 1;
                q.emplace(r, c + 1);
            }
        }

        return mat;
    }
};