class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        vector<int> ans;
        ans.push_back(nums[0]);
        int j=1;
        
        for(int i=0; i<n-1; i++){
            if(nums[i]!=nums[i+1]){
                nums[j] = nums[i+1];
                j++;
            }
        }

        return j;
    }
};