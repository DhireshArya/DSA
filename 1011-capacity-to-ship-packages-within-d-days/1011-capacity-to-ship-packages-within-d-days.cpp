class Solution {
public:
    int sum(vector<int> weights){
        int n = weights.size();
        int s = 0;
        for(int i=0; i<n; i++){
            s = s + weights[i]; 
        }
        return s;
    }

    int max(vector<int> weights){
        int max = weights[0];
        for(int i=1; i<weights.size(); i++){
            if(weights[i]>max){
                max = weights[i];
            }
        }
        return max;
    }

    bool check(vector<int> weights, int mid, int days){
        int n = weights.size();
        int count = 0;
        int sum = 0;
        
        for(int i=0; i<n; i++){
            if(sum+weights[i]>mid){
                count++;
                sum = 0;
                i--;
            }
            else{
                sum = sum + weights[i];
            }
        }
        if(sum>0){
            count++;
        }

        if(count <= days){
            return true;
        }
        return false;
    }

    
    int shipWithinDays(vector<int>& weights, int days) {
        int start = max(weights);
        int end = sum(weights);
        int ans = -1;

        while(start <= end){
            int mid = start+(end-start)/2;

            if(check(weights,mid,days)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};