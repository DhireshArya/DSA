class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string temp;

        vector<string> ans;
        while(ss>>temp){
            ans.push_back(temp);
        }

        reverse(ans.begin(), ans.end());
        string fs="";
        for(int i=0; i<ans.size(); i++){
            if(i==ans.size()-1){
                fs = fs + ans[i];
            }
            else{
                fs = fs + ans[i] + " "; 
            }
        }
        return fs;
    }
};