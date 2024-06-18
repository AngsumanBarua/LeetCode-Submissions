class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        pair <int,int> vp[n+3];
        for(int i=0;i<n;i++){
            vp[i]=make_pair(difficulty[i],profit[i]);
        }
        sort(vp,vp+n);
        int mx=0;
        int mxx[n+1];
        for(int i=0;i<n;i++){
            mx=max(mx,vp[i].second);
            mxx[i]=mx;
        }
        int wo=worker.size();
        int ans=0;
        for(int i=0;i<wo;i++){
            int l=0,r=n-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(vp[mid].first<=worker[i]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            if(l-1>=0){
                ans+=mxx[l-1];
            }
        }
        return ans;
    }
};