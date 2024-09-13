class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector <vector <int>> v;
        for(int i=0;i<n;i++){
            vector <int> temp(33,0);
            int k=0,a=arr[i];
            while(a){
                if(a&1){
                    temp[k]=1;
                }
                k++;
                a/=2;
            }
            if(i>0){
                for(int j=0;j<32;j++){
                    temp[j]+=v[i-1][j];
                }
            }
            v.push_back(temp);
        }
        int q=queries.size();
        vector <int> ans;
        int two[33];
        two[0]=1;
        for(int i=1;i<31;i++){
            two[i]=two[i-1]*2;
        }
        for(int i=0;i<q;i++){
            int cur=0;
            if(queries[i][0]==0){
                for(int j=0;j<32;j++){
                    if(v[queries[i][1]][j]&1){
                        cur+=two[j];
                    }
                }
            }
            else{
                for(int j=0;j<32;j++){
                    if((v[queries[i][1]][j]-v[queries[i][0]-1][j])&1){
                        cur+=two[j];
                    }
                }
            }
            ans.push_back(cur);
        }
        return ans;
    }
};