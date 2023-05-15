class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, compare> pq(points.begin(), points.end());
        
        for (int i = 0; i < k; ++i)
        {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }

private:
    struct compare {
        bool operator()(vector<int>& p, vector<int>& q)
        {
            return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
        }
    };
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        nth_element(points.begin(), points.begin() + k, points.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};