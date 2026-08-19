class Solution {
public:
    void change(TreeNode* &root){
        if(root==NULL){
            return;
        }
        swap(root->left, root->right);
        change(root->left);
        change(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        change(root);
        return root;
    }
};