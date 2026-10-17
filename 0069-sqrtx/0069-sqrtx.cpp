class Solution {
public:
    int mySqrt(int x) {
        int s = 0;
        int e = x;


        while(s<=e){
            int mid = s+(e-s)/2;
            long long value = (long long)mid*(long long)mid;
            if(value == (long long)x){
                return mid;
            }
            else if(value > (long long)x){
                e = mid-1;
            }
            else{
                s = mid + 1;
            }
        }
        return e;
    }
};