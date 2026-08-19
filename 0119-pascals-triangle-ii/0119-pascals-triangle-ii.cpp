class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<vector<int>> arr(rowIndex+1);
        for(int i=0; i<=rowIndex; i++){
            arr[i] = vector<int> (i+1);
            for(int j=0; j<=i; j++){
                if(j==0 || j==i){
                    arr[i][j] = 1;
                }
                else{
                    arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
                }
            }
        }
        return arr[rowIndex];
    }
};