class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        unordered_set<string> us;


        for(int i=0; i<n; i++){
            string s = words[i];
            reverse(s.begin(), s.end());

            if(us.find(s) == us.end()){
                us.insert(words[i]);
            }
        }
        return n-us.size();
    }
};