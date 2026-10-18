class Solution {
public:
    bool isPerfectSquare(int num) {
        int s = 0;
        int e = num;
        bool b = false;

        while(s <= e){
            int mid = s+(e-s)/2;
            long long value = (long long)mid*(long long)mid;

            if(value == num){
                b = true;
                break;
            }
            else if(value > num){
                e = mid-1;
            }
            else if(value < num){
                s = mid+1;
            }
        }
        return b;
    }
};