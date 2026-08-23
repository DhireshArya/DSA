class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n!=m){
            return false;
        }
        else{
            // for the first string
            int arr1[26] = {0};
            for(int i=0; i<n; i++){
                int b = s[i]-'a';
                arr1[b] = arr1[b] + 1;
            }

            // for the second string
            int arr2[26] = {0};
            for(int i=0; i<m; i++){
                int b = t[i]-'a';
                arr2[b] = arr2[b] + 1;
            }

            for(int i=0; i<26; i++){
                if(arr1[i]!=arr2[i]){
                    return false;
                }
            }

            return true;
        }
        
    }
};