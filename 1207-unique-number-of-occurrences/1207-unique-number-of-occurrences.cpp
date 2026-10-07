class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> mpp;

        for(int i=0; i<n; i++){
            mpp[arr[i]]++;
        }

        // make a set
        unordered_set<int> stt;
        for(auto it:mpp){
            stt.insert(it.second);
        }

        if(mpp.size()==stt.size()){
            return true;
        }
        return false;
    }
};