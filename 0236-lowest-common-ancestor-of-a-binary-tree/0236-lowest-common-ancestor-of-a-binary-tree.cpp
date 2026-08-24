class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(root->val==p->val || root->val==q->val){
            return root;
        }
         
        if(left==NULL && right==NULL){
            return NULL;
        }

        if(left != NULL && right != NULL){
            return root;
        }
        
        if(left==NULL && right!=NULL){
            return right;
        }
        else if(right==NULL && left!=NULL){
            return left;
        }
        return NULL;
    }
};