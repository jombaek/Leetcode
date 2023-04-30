/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if (!root)
            return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        
        q.push(root);

        while (!q.empty())
        {
            vector<int> row;
            int n = q.size();

            while (n--)
            {
                TreeNode* cur = q.front();
                row.push_back(q.front()->val);
                q.pop();
                
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }

            ans.push_back(row);
        }

        return ans;
    }
};