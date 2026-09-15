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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);
        int lvl=0;

        while(!q.empty()){
            int size = q.size();
            vector<int> tmp;
            while(size--){
                TreeNode* t = q.front();
                q.pop();
                tmp.push_back(t->val);
                
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right); 
            }
            if(lvl%2!=0){
                    reverse(tmp.begin(),tmp.end());
                }
            ans.push_back(tmp);
            lvl++;
        }
        return ans;
    }
};