class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        int mp[k+3];
        memset(mp,0,sizeof(mp));
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                mp[arr[i]%k]++;
            }
            else{
                int m=arr[i]/k;
                if(m<0){
                   m*=-1; 
                }
                if(arr[i]%k!=0){
                    m++;
                }
                arr[i]+=(m*k);
                //cout << arr[i] << endl;
                mp[arr[i]]++;
            }
        }
        bool ans=true;
        if(mp[0]&1){
            ans=false;
        }
        for(int i=1;i<=(k/2) && ans;i++){
            if(mp[i]!=mp[k-i]){
                ans=false;
                break;
            }
        }
        return ans;
    }
};