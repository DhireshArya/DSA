class Solution {
public:
    int lowerbound(vector<int>& arr, int x){
        int n = arr.size();
        int start = 0;
        int end = n-1;
        bool flag = false;

        while(start <= end){
            int mid = start + (end-start)/2;
            if(arr[mid]==x){
                flag = true;
                return mid-1;
            }
            else if(arr[mid]<x){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        if(flag == false){
            return end;
        }
        return -1;
    }

    int upperbound(vector<int>& arr, int x){
        int n = arr.size();
        int start = 0;
        int end = n-1;
        bool flag = false;

        while(start<= end){
            int mid = start+(end-start)/2;
            if(arr[mid]==x){
                flag=true;
                return mid+1;
            }
            else if(arr[mid]<x){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        if(flag == false){
            return start;
        }
        return -1;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int idx = -1;
        bool b1 = false;   // lowerbound
        bool b2 = false;

        if(x>arr[0] && x<arr[n-1]){  
            idx = lowerbound(arr, x);
            b1 = true;
        }
        else if(x <= arr[0]){   
            idx = upperbound(arr, x);
            b2 = true;
        }
        else{                 
            idx = lowerbound(arr, x);
            b1 = true;
        }


        int s = -1;
        int e = -1;
        if(b1==true && b2==false){   // case of lowerbound
            s = idx;
            e = idx+1;
        }
        else{
            s = idx-1;
            e = idx;
        }

        vector<int> ans;
        int count = 0;
        while(s>=0 || e<n){
            if(s<0){
                ans.push_back(arr[e]);
                e++;
                count++;
            }
            else if(e>=n){
                ans.push_back(arr[s]);
                s--;
                count++;
            }
            else if((abs(x-arr[s]) < abs(x-arr[e])) ||
                    (abs(x-arr[s]) == abs(x-arr[e]) && arr[s]<arr[e])){
                ans.push_back(arr[s]);
                count++;
                s--;
            }
            else{
                ans.push_back(arr[e]);
                count++;
                e++;
            }

            if(count==k){
                break;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};