class Solution {
public:
    void path(TreeNode* root, vector<string> &st, string s){
        if(root==NULL){
            return;
        }

        if(root->left==NULL && root->right==NULL){
            s = s+to_string(root->val);
            st.push_back(s);
            return;
        }

        s = s + to_string(root->val) + "->";

        path(root->left, st, s);
        path(root->right, st, s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<string> st;
        string s = "";
        path(root, st, s);

        return st;
        
    }
};