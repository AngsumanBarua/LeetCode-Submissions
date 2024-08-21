class Solution {
public:
    void fun(int ind, int cur, vector<vector<int>> &ans,vector<int>& cand,vector<int>& v,int tar,int n){
        if(ind==n){
            if(cur==tar){ans.push_back(v);}
            return;
        }
        if(cur+cand[ind]<=tar){
            v.push_back(cand[ind]);
            fun(ind,cur+cand[ind],ans,cand,v,tar,n);
            v.pop_back();
        }
        fun(ind+1,cur,ans,cand,v,tar,n);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        int n=cand.size();
        vector<vector<int>> ans;
        vector <int> v;
        int cur=0,ind=0;
        fun(ind,cur,ans,cand,v,target,n);
        return ans;
    }
};