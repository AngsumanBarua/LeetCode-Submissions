class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& ori, int m, int n) {
        vector<vector<int>> ans;
        int l=ori.size();
        if(l==n*m){
            int k=0;
            for(int i=0;i<m;i++){
                vector <int> v;
                for(int j=0;j<n;j++){
                    v.push_back(ori[k]);
                    k++;
                }
                ans.push_back(v);
            }
        }
        return ans;
    }
};