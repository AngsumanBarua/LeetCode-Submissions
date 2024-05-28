class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length();
        int val[n+2];
        int ans=0;
        for(int i=0;i<n;i++){
            val[i]=abs(s[i]-t[i]);
            if(i!=0){
                val[i]+=val[i-1];
            }
            //cout << val[i] << endl;
            if(val[i]<=maxCost){
                ans=i+1;
            }
        }
        for(int i=0;i<n;i++){
            int l=0,r=i;
            while(l<=r){
                int mid=(l+r)/2;
                if((val[i]-val[mid])<=maxCost){
                    ans=max(ans,i-mid);
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
        }
        return ans;
    }
};