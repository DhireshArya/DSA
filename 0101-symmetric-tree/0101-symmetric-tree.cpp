class Solution {
public:
    bool symmetric(TreeNode* root1, TreeNode* root2){
        if(root1==NULL && root2==NULL){
            return true;
        }
        else if((root1!=NULL && root2==NULL) || (root1==NULL && root2!=NULL)){
            return false;
        }

        bool make1 = symmetric(root1->left, root2->right);
        if(make1==false){
            return false;
        }
        bool make2 = symmetric(root1->right, root2->left);
        if(make2==false){
            return false;
        }

        bool make3;
        if(root1->val == root2->val){
            make3 = true;
        }
        else{
            make3 = false;
        }

        if(make1==true && make2==true && make3==true){
            return true;
        }

        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        bool actual = symmetric(root->left,root->right);
        return actual;
    }
};