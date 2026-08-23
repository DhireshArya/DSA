class Solution {
public:
    int mostWordsFound(vector<string>& s) {
        int n = s.size();
        
        int max = 0;
        for(int i=0; i<n; i++){
            int count = 0;
            stringstream ss(s[i]);
            string temp;
            while(ss>>temp){
                count++;
            }

            if(count>max){
                max = count;
            }
        }

        return max;
    }
};