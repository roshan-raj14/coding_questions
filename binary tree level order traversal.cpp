// leetcode 102 - Binary Tree Level Order Traversal

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
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<vector<int>> ans;
        vector<int> v;

        if(root == NULL)    //ye case ko handle nahi kiye the isliye fas rhe the
        return ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while( !q.empty() )
        {
            TreeNode* temp = q.front();
            q.pop();

            if(temp == NULL)
            {
                ans.push_back( v );
                v.resize(0);    //faster than v.clear()

                if( !q.empty() )
                q.push(NULL);
            }
            else
            {
                v.push_back( temp->val );

                if(temp->left != NULL)
                q.push(temp->left);

                if(temp->right != NULL)
                q.push(temp->right);
            }
        }
        return ans;  
    }
};

// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         if(root==NULL){
//             vector<vector<int>> v;
//             return v;
//         }
//         queue<TreeNode*>q;
//         q.push(root);
//         q.push(NULL);
//         vector<vector<int>>ans;
//         vector<int>temp;
//         while(!q.empty()){
//             TreeNode* node=q.front();
//             q.pop();
//             if(node){
//                 if(node->left) q.push(node->left);
//                 if(node->right) q.push(node->right);
                
//                 temp.push_back(node->val);
//             }
//             else
//             {
//                 ans.push_back(temp);
//                 temp.resize(0);
                
//                 if(!q.empty())
//                 {
//                     q.push(NULL);
//                 }
//             }
//         }
//         return ans;
//     }
// };
