/*

PROBLEM STATEMENT : 

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]



*/

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
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> result;
        bool reverse_flag = false;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> lvl;
            while (size-- > 0)
            {
                root = q.front();
                q.pop();
                lvl.push_back(root->val);
                if (root->left != NULL)
                    q.push(root->left);
                if (root->right != NULL)
                    q.push(root->right);
            }
            if (reverse_flag)
            {
                reverse(lvl.begin(), lvl.end());
            }
            result.push_back(lvl);

            reverse_flag = !reverse_flag;
        }

        return result;
    }
};