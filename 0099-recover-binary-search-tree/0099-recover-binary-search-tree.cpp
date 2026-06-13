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
    TreeNode* prev= NULL;
    int galat = 0;
    TreeNode* g1First= NULL;
    TreeNode* g1Second= NULL;
    TreeNode* g2First= NULL;
    TreeNode* g2Second= NULL;
    void fun(TreeNode* root){
        if(root==NULL)
            return;
        fun(root->left);
        if(prev==NULL)
            prev=root;
        else{
            if(root->val<prev->val){
                if(galat==0){
                    g1First=prev;
                    g1Second=root;
                    galat++;
                }
                else{
                    g2First=prev;
                    g2Second=root;
                    galat++;
                }
            }
            prev=root;
        }
        fun(root->right);
    }
    void recoverTree(TreeNode* root) {
        fun(root);
        if(galat==1)
            swap(g1First->val,g1Second->val);
        else
            swap(g1First->val,g2Second->val);
        return;            
    }
};