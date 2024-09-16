class Solution {
public:
    int findTheLongestSubstring(string s) {
        int l=s.length();
        int xr=0;
        vector <int> mp(32,-1);
        int ans=0;
        for(int i=0;i<l;i++){
            int val;
            if(s[i]=='a'){
                val=1;
            }
            else if(s[i]=='e'){
                val=2;
            }
            else if(s[i]=='i'){
                val=4;
            }
            else if(s[i]=='o'){
                val=8;
            }
            else if(s[i]=='u'){
                val=16;
            }
            else{
                val=0;
            }
            xr^=val;
            if(xr==0){
                ans=i+1;
            }
            else if(mp[xr]==-1){
                mp[xr]=i;
            }
            else{
                ans=max(ans,i-mp[xr]);
            }
            //cout << xr << " " << ans << endl;
        }
        return ans;
    }
};