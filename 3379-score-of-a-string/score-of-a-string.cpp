class Solution {
public:
    int scoreOfString(string s) {
        int l=s.length();
        int ans=0;
        for(int i=1;i<l;i++){
            ans+=abs((s[i]-'a')-(s[i-1]-'a'));
        }
        return ans;
    }
};