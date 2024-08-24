class Solution {
public:
    void fun(int ind, int cur, vector<vector<int>> &ans,vector<int>& cand,vector<int>& v,int tar,int n){
        if(cur==tar){
            ans.push_back(v);
            return;
        }
        if(ind==n){
            return;
        }
        for(int i=ind;i<n;i++){
            if((i==ind || cand[i]!=cand[i-1]) && cur+cand[i]<=tar){
                v.push_back(cand[i]);
                fun(i+1,cur+cand[i],ans,cand,v,tar,n);
                v.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(),cand.end());
        int n=cand.size();
        vector<vector<int>> ans;
        vector <int> v;
        fun(0,0,ans,cand,v,target,n);
        return ans;
    }
};