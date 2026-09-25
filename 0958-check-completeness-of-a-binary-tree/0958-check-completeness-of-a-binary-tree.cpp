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
    bool nullSeen = false;
    bool res = true;

    void level(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node==nullptr) nullSeen = true;
            else{
                if(nullSeen){
                     res = false;
                }
                q.push(node->left);
                q.push(node->right);
            }
        }
    }
public:
    bool isCompleteTree(TreeNode* root) {
        if(root==nullptr) return true;

        level(root);

        return res;
    }
};