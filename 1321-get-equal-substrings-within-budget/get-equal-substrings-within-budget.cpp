class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length();
        int ans=0,cur=0,l=0;
        for(int i=0;i<n;i++){
            cur+=abs(s[i]-t[i]);
            while(cur>maxCost){
                cur-=abs(s[l]-t[l]);
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};