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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;

        if(root==nullptr) return ans;

        q.push(root);

        while(!q.empty()){
            int size=q.size();
            vector<int> tmp;
            while(size--){
                TreeNode* t = q.front();
                q.pop();

                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);

                tmp.push_back(t->val);
            }
            ans.push_back(tmp);
        }

        return ans;
    }
};