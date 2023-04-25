class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        vector<unordered_set<int>> rows(9), cols(9), blocks(9);

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                {
                    int cur = board[i][j] - '0';
                    if (rows[i].count(cur) || cols[j].count(cur) || blocks[(i / 3) * 3 + j / 3].count(cur))
                        return false;

                    rows[i].insert(cur);
                    cols[j].insert(cur);
                    blocks[(i / 3) * 3 + j / 3].insert(cur);
                }
            }
        }
    
        return true;
    }   
};