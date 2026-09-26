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
    TreeNode* prev = nullptr;
    int wrongs = 0;
    pair<TreeNode*,TreeNode*> w1;
    pair<TreeNode*,TreeNode*> w2;

    void inorder(TreeNode* root){
        if(root==nullptr) return;

        inorder(root->left);

        if(prev == nullptr){
            prev = root;
        }
        else{
            if(root->val <= prev->val){
                if(wrongs==0){
                    w1.first = prev;
                    w1.second = root;
                    wrongs++;
                }
                else{
                    w2.first = prev;
                    w2.second = root;
                    wrongs++;
                }
            }
            prev = root;
        }
        inorder(root->right);

        return;
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root);

        if(wrongs==1){
            swap(w1.first->val,w1.second->val);
        }
        else{
            swap(w1.first->val,w2.second->val);
        }

        return;
    }
};