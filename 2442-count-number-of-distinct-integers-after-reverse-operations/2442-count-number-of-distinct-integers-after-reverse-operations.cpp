class Solution {
public:
    int reverse(int num){
        int fele = 0;
        while(num != 0){
            int ele = num%10;
            fele = fele*10 + ele;
            num =  num/10;
        } 
        return fele;
    }

    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> us;
        for(int i=0; i<n; i++){
            us.insert(nums[i]);
        }

        for(int i=0; i<n; i++){
            int ele = reverse(nums[i]);
            us.insert(ele);
        }

        return us.size();
    }
};