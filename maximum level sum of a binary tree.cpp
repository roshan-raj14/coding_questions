//leetcode 1161 - maximum level sum of a binary tree

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
    int maxLevelSum(TreeNode* root)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        pair<int,int> sum_level;
        sum_level.first = INT_MIN;
        sum_level.second = 0;
        int temp_sum = 0;
        int level = 1;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while( !q.empty() )
        {
            TreeNode* temp = q.front();
            q.pop();

            if(temp)
            {
                temp_sum += temp->val;

                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);
            }
            else
            {
                if( temp_sum > sum_level.first )
                {
                    sum_level.first = temp_sum;
                    sum_level.second = level;
                } 

                temp_sum = 0;
                level++;

                if( !q.empty() )
                q.push(NULL);
            }
        }
        return sum_level.second;
    }
};
