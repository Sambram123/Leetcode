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
    unordered_map<int,int> m;
    int idx = 0;

    TreeNode* make(vector<int>& preorder, int low, int high){
        if(low>high) return nullptr;
        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;
        int id = m[node->val];

        node->left = make(preorder,low,id-1);
        node->right = make(preorder,id+1,high);

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++){
            m[inorder[i]] = i;
        }

        TreeNode* node = make(preorder,0,n-1);
        return node; 
    }
};