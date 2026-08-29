class Solution {
public:
    void leftSubtree(TreeNode* root,
                 vector<pair<int, pair<int,int>>> &a,
                 pair<int, pair<int,int>> p){

        if(root == NULL){
            return;
        }

        p.first = root->val;
        a.push_back(p);

        // coordinates for left child
        pair<int,pair<int,int>> left = p;
        left.second.first++;
        left.second.second--;

        // coordinates for right child
        pair<int,pair<int,int>> right = p;
        right.second.first++;
        right.second.second++;

        leftSubtree(root->left, a, left);
        leftSubtree(root->right, a, right);
    }


    void rightSubtree(TreeNode* root,
                  vector<pair<int, pair<int,int>>> &a,
                  pair<int, pair<int,int>> p){

        if(root == NULL){
            return;
        }

        p.first = root->val;
        a.push_back(p);

        // coordinates for left child
        pair<int,pair<int,int>> left = p;
        left.second.first++;
        left.second.second--;

        // coordinates for right child
        pair<int,pair<int,int>> right = p;
        right.second.first++;
        right.second.second++;

        rightSubtree(root->left, a, left);
        rightSubtree(root->right, a, right);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }

        vector<pair<int, pair<int,int>>> a;

        pair<int,pair<int,int>> rootPos = {root->val,{0,0}};
        a.push_back(rootPos);

        // Pass the correct coordinates of children
        leftSubtree(root->left, a, {0,{1,-1}});
        rightSubtree(root->right, a, {0,{1,1}});

        sort(a.begin(),a.end(),[](auto &x, auto &y){

            if(x.second.second != y.second.second)
                return x.second.second < y.second.second;

            if(x.second.first != y.second.first)
                return x.second.first < y.second.first;

            return x.first < y.first;
        });


        // code for finding the level of the binary tree
        vector<vector<int>> ans;
        vector<int> col;

        int prevCol = a[0].second.second;

        for(auto &it : a){

            if(it.second.second != prevCol){
                ans.push_back(col);
                col.clear();
                prevCol = it.second.second;
            }

            col.push_back(it.first);
        }

        ans.push_back(col);

        return ans;
    }
};