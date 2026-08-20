class Solution {
public:
    void path(TreeNode* root, vector<string> &st, string &s){
        if(root==NULL){
            return;
        }

        string old = s;   // save state

        if(root->left==NULL && root->right==NULL){
            s = s+to_string(root->val);
            st.push_back(s);
            s = old;        // restore
            return;
        }

        s = s + to_string(root->val) + "->";

        path(root->left, st, s);
        path(root->right, st, s);

        s = old;    // backtrack
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