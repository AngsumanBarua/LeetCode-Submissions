class Solution {
public:
    bool isV(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int l=words.size();
        vector <int> preSum(l+1);
        for(int i=0;i<l;i++){
            int ls=words[i].length();
            if(i>0){
                preSum[i]=preSum[i-1];
            }
            if(isV(words[i][0]) && isV(words[i][ls-1])){
                preSum[i]++;
            }
        }
        int q=queries.size();
        vector <int> ans;
        for(int i=0;i<q;i++){
            if(queries[i][0]==0){
                ans.push_back(preSum[queries[i][1]]);
            }
            else{
                ans.push_back(preSum[queries[i][1]]-preSum[queries[i][0]-1]);
            }
        }
        return ans;
    }
};