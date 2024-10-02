class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector <int> ans(n);
        map <int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        int k=1;
        for(auto it:mp){
            int m=it.second.size();
            for(int j=0;j<m;j++){
                ans[it.second[j]]=k;
            }
            k++;
        }
        return ans;
    }
};