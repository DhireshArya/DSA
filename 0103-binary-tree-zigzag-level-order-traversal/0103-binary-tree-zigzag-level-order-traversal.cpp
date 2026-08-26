class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if(root==NULL){
            return {};
        }

        // we will be using concept of queue
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        q.push(root);
        q.push(NULL);

        int count = -1;

        vector<int> a;
        while(!q.empty()){
            if(q.front()==NULL){
                count++;
                if(count%2!=0){  // odd 
                    reverse(a.begin(), a.end());
                }
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