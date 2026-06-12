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
    TreeNode* ans = NULL;
    void fun(TreeNode* node, int k){
        if(node== NULL)
            return;
        if(node->val == k){
            ans=node;
            return;
        }
        if(node->val>k){
            fun(node->left,k);
        }else{
            fun(node->right,k);
        }
        return;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        fun(root,val);
        return ans;
    }
};