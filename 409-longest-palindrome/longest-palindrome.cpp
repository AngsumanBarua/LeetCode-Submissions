class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        int ch[53];
        memset(ch,0,sizeof(ch));
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z'){
                ch[s[i]-'a']++;
            }
            else{
                ch[s[i]-'A'+26]++;
            }
        }
        int ans=0;
        for(int i=0;i<52;i++){
            if(ch[i]&1){
                ans+=ch[i]-1;
                if(!(ans&1)){
                    ans++;
                }
            }
            else{
                ans+=ch[i];
            }
        }
        return ans;
    }
};