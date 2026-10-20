class Solution {
public:
    int peakIndex(MountainArray &arr){
        int n = arr.length();
        int start = 1;
        int end = n-2;

        while(start<=end){
            int mid = start + (end-start)/2;

            int midValue = arr.get(mid);
            int nextValue = arr.get(mid+1);
            int prevValue = arr.get(mid-1);

            if(midValue>nextValue && midValue>prevValue){
                return mid;
            }
            else if(midValue<nextValue){
                start=mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }

    int rFirstOccurence(MountainArray &arr, int target, int idx){
        int n = arr.length();
        int start = idx+1;
        int end = n-1;
        int ans = -1;

        while(start<=end){
            int mid = start + (end-start)/2;

            int midValue = arr.get(mid);

            if(midValue==target){
                ans = mid;
                end = mid-1;
            }
            else if(target>midValue){
                end = mid-1;
            }
            else if(target<midValue){
                start = mid+1;
            }
        }
        return ans;
    }

    int lFirstOccurence(MountainArray &arr, int target, int idx){
        int n = arr.length();
        int start = 0;
        int end = idx;
        int ans = -1;

        while(start<=end){
            int mid = start + (end-start)/2;

            int midValue = arr.get(mid);

            if(midValue==target){
                ans = mid;
                end = mid-1;
            }
            else if(target>midValue){
                start = mid+1;
            }
            else if(target<midValue){
                end = mid-1;
            }
        }
        return ans;
    }


    int findInMountainArray(int target, MountainArray &mountainArr) {
        int idx = peakIndex(mountainArr);

        // first search in the left side
        int lidx = lFirstOccurence(mountainArr, target, idx);

        if(lidx != -1){
            return lidx;
        }
        else{
            int ridx = rFirstOccurence(mountainArr, target, idx);
            return ridx;
        }
    }
};