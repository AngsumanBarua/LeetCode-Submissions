class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cur=0;
        int n=logs.size();
        for(int i=0;i<n;i++){
            int m=logs[i].length();
            if(m==3 && logs[i][0]=='.' && logs[i][1]=='.'){
                if(cur!=0){
                    cur--;
                }
            }
            else if(m==2 && logs[i][0]!='.' || m>=3){
                cur++;
            }
        }
        return cur;
    }
};