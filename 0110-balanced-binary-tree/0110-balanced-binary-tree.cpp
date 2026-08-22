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

    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);

        return max(left,right)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        bool left1 = isBalanced(root->left);
        if(left1==false){
            return false;
        }
        bool right1 = isBalanced(root->right);
        if(right1==false){
            return false;
        }


        int left2 = height(root->left);
        int right2 = height(root->right);

        if(abs(left2-right2)<=1){
            return true;
        }
        else{
            return false;
        }
    }
};