class Solution {
public:
    bool find(TreeNode* root, int targetSum, int value){

        if(root==NULL){
            return false;
        }

        value = value + root->val;

        if(root->left==NULL && root->right==NULL){
            if(value == targetSum){
                return true;
            }
            else{
                return false;
            }
        }

        bool left = find(root->left, targetSum, value);
        if(left==true){
            return true;
        }
        bool right = find(root->right, targetSum, value);
        if(right == true){
            return true;
        }

        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        bool ans = find(root, targetSum, 0);
        return ans;
    }
};