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
    void solve(TreeNode* root, string s, int &finalAns){
        if(root==NULL){
            return;
        }

        s = s+to_string(root->val);

        if(root->left==NULL && root->right==NULL){
            int a = stoi(s);
            finalAns = finalAns + a;
            return;
        }

        solve(root->left, s, finalAns);
        solve(root->right, s, finalAns);

    }
    int sumNumbers(TreeNode* root) {
        string ans = "";
        int finalAns = 0;
        
        solve(root, ans, finalAns);
        return finalAns;
        
    }
};