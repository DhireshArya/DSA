class Solution {
public:
    int value(int n){
        int sum = 0;
        while(n!=0){
            int digit = n%10;
            sum = sum + digit;
            n = n/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(value(nums[i]) == i){
                return i;
            }
        }
        return -1;
    }
};