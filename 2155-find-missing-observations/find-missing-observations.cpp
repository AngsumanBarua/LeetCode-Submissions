class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int tot=(m+n)*mean;
        int cur=0;
        for(int i=0;i<m;i++){
            cur+=rolls[i];
        }
        vector <int> ans;
        int d=(tot-cur)/n;
        int mod=(tot-cur)%n;
        //cout << tot << "  " << cur << endl;
        if(d>=1 && d<=5 || d==6 && mod==0){
            for(int i=0;i<n;i++){
                ans.push_back(d);
                if(mod){
                    ans[i]++;
                    mod--;
                }
            }
        }
        return ans;
    }
};