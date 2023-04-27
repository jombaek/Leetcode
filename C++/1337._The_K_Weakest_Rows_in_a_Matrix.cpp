class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
        int m = mat.size();
        int n = mat[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> ans;

        for (int i = 0; i < m; ++i)
        {
            int l = 0;
            int r = n;

            while (l < r)
            {
                int mid = l + (r - l) / 2;

                if (mat[i][mid] == 0)
                    r = mid;
                else
                    l = mid + 1;
            }

            pq.push({l, i});
        }

        while (k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};