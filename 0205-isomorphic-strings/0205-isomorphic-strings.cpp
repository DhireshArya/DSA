class Solution {
public:
    bool isIsomorphic(string s, string t) {
        bool first = true;
        int m = s.length();
        int n = t.length();
        if(m != n){
            return false;
        }

        char str[256] = {'\0'};

        for(int i=0; i<m; i++){
            int idx = s[i];
            if(str[idx] == '\0'){
                str[idx] = t[i];
            }
            else{
                if(str[idx] != t[i]){
                    first = false;
                    break;
                }
            }
        }


        // checking for the second string
        bool second = true;
        char str1[256] = {'\0'};
        for(int i=0; i<n; i++){
            int idx = t[i];
            if(str1[idx] == '\0'){
                str1[idx] = s[i];
            }
            else{
                if(str1[idx] != s[i]){
                    second = false;
                    break;
                }
            }
        }

        if(first && second){
            return true;
        }

        return false;
    }
};