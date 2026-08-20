class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        // 1. make all the elements of column 1 to "1"
        for(int i=0; i<row; i++){
            if(grid[i][0]==0){
                for(int j=0; j<col; j++){
                    if(grid[i][j] == 0){
                        grid[i][j] = 1;
                    }else{
                        grid[i][j] = 0;
                    }
                }
            }
        }


        // now apply to the columns, try to make maximum number of "1" in the rest columns
        for(int i=1; i<col; i++){
            // 1. first count the number of '0' and '1'
            int count1 = 0;
            int count0 = 0;
            for(int j=0; j<row; j++){
                if(grid[j][i]==0){
                    count0++;
                }
                else{
                    count1++;
                }
                
            }

            if(count0>count1){
                // now change the "0" of that columns into "1"
                for(int j=0; j<row; j++){
                    if(grid[j][i]==0){
                        grid[j][i] =1;
                    }
                    else{
                        grid[j][i] = 0;
                    }
                }
            }
        }

        // find the sum of all the elements of the grid
        int sum = 0;
        for(int i=0; i<row; i++){
            int value = 0;
            for(int j=0; j<col; j++){
                value = value*2+grid[i][j];
            }
            sum = sum + value;
        }

        return sum;


    }
};