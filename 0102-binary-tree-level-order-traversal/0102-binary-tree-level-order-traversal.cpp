class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root==NULL){
            return {};
        }

        // we will be using concept of queue
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        q.push(root);
        q.push(NULL);

        vector<int> a;
        while(!q.empty()){
            if(q.front()==NULL){
                ans.push_back(a);
                q.pop();
                a = {};
                if(!q.empty()){
                    q.push(NULL);
                }  
            }
            else{
                a.push_back(q.front()->val);
                if(q.front()->left!=NULL){
                    q.push(q.front()->left);
                }
                if(q.front()->right!=NULL){
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }
        return ans;
    }
};