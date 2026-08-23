class Solution {
public:
    int countValidWords(string s) {
        int n = s.size();

        stringstream ss(s);
        string temp;

        int count = 0;
        while(ss>>temp){

            vector<pair<int, char>> a;    // lowercase letters
            vector<pair<int, char>> b;   // digits
            vector<pair<int, char>> c;   // hypens
            vector<pair<int, char>> d;   // punctuation

            int m = temp.size();

            // S1: saare digit aur uske index ko count karo
            for(int i=0; i<m; i++){
                if(temp[i]>=97 && temp[i]<=122){
                    a.push_back({i, temp[i]});
                }
                else if(temp[i]>=48 && temp[i]<=57){
                    b.push_back({i, temp[i]});
                }
                else if(temp[i]==45){
                    c.push_back({i, temp[i]});
                }
                else{
                    d.push_back({i, temp[i]});
                }
            }

            // S2: ab "temp" ke andar saare arrangement check karo
            int count5 = 0;
            
            // digits case resolved
            bool b1 = false;
            if(b.size()==0){ 
                b1 = true;
                count5++;
            }

            // hyphen case resolved
            bool b2 = false;
            if(c.size()<=1){
                if(c.size()==0){
                    b2 = true;
                }

                // checking if it is surrounded by lowercase alphabets or not
                for(auto it:c){
                    int idx = it.first;

                    // must be surrounded by lowercase alphabets
                    if((idx!=0 && idx!=m-1) && (temp[idx-1]>=97 && temp[idx-1]<=122) && (temp[idx+1]>=97 && temp[idx+1]<=122)){
                        b2 = true;
                    }

                }
            }
            if(b2==true){
                    count5++;
            }

            // punctuation case resolved
            bool b3 = false;
            if(d.size()<=1){
                if(d.size()==0){
                    b3 = true;
                }
                
                if(m==1){
                    if(temp[0]=='!' || temp[0]=='.' || temp[0]==','){
                        b3 = true;
                    }
                }

                for(auto it:d){
                    int idx = it.first;
                    if(idx == m-1){
                        b3 = true;
                    }
                }

            }
            if(b3==true){
                    count5++;
                }
            

            if(count5==3){
                count++;
            }
        }

        return count;
    }
};