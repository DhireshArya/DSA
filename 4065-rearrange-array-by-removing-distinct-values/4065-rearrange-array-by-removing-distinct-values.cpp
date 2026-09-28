class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        unordered_map<int, int> mpp;

        for(int i=0; i<nums.size(); i++){

            // case of absent
            if(mpp.find(nums[i]) == mpp.end()){
                mpp[nums[i]] = 1;
            }
            else{ // case of present
                mpp[nums[i]]++;
            }
        }

        vector<int> ans;

        // find the element with the largest count
        int max = -1;
        for(auto it: mpp){
            if(it.second > max){
                max = it.second;
            }
        }

        int length = 0;
        for(int i=0; i<max; i++){
            for(auto &it: mpp){
                if(it.second != 0){
                    int ele = it.first;
                    ans.push_back(ele);
                    it.second--;
                }  
            }
            sort(ans.begin()+length, ans.end());
            length = ans.size();
        }

        return ans;

    }
};