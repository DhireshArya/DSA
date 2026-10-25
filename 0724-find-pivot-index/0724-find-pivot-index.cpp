class Solution {
public:
    int leftSum(vector<int> nums, int i){
        int n = nums.size();
        if(i==0){
            return 0;
        }

        int sum = 0;
        for(int k=0; k<i; k++){
            sum = sum + nums[k];
        }
        return sum;
    }
    int rightSum(vector<int> nums, int i){
        int n = nums.size();
        if(i==n-1){
            return 0;
        }

        int sum = 0;
        for(int k=i+1; k<n; k++){
            sum = sum + nums[k];
        }
        return sum;
    }

    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int left = leftSum(nums, i);
            int right = rightSum(nums, i);
            if(left == right){
                return i;
            }
        }
        return -1;
    }

};