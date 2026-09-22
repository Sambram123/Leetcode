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
    stack<TreeNode*> asc;
    stack<TreeNode*> desc;

    TreeNode* getSmall(){
        TreeNode* small = asc.top();
        asc.pop();
        TreeNode * rightChild = small->right;
        while(rightChild){
            asc.push(rightChild);
            rightChild=rightChild->left;
        }
        return small;
    }
    TreeNode* getBig(){
        TreeNode* big = desc.top();
        desc.pop();
        TreeNode* leftChild = big->left;
        while(leftChild){
            desc.push(leftChild);
            leftChild=leftChild->right;
        }
        return big;
    }

public:
    bool findTarget(TreeNode* root, int k) {

        TreeNode* tmp = root;
        while(tmp){
            asc.push(tmp);
            tmp=tmp->left;
        }
        tmp = root;
        while(tmp){
            desc.push(tmp);
            tmp=tmp->right;
        }

        TreeNode* i = getSmall();
        TreeNode* j = getBig();

        while((i&&j) && (i!=j) && (i->val < j->val)){
            int sum = i->val + j->val;
            if(sum == k)
                return true;
            else if(sum < k)
                i = getSmall();
            else
                j = getBig();
        }
        return false;
    }
};