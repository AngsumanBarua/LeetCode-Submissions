class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();
        bool ans=false;
        if(n1<=n2){
            int cnt[26];
            memset(cnt,0,sizeof(cnt));
            for(int i=0;i<n1;i++){
                cnt[s1[i]-'a']++;
            }
            for(int i=0;i<n1;i++){
                cnt[s2[i]-'a']--;
            }
            ans=true;
            for(int i=0;i<26;i++){
                if(cnt[i]!=0){
                    ans=false;
                    break;
                }
            }
            for(int i=n1,j=0;i<n2 && !ans;i++,j++){
                cnt[s2[i]-'a']--;
                cnt[s2[j]-'a']++;
                ans=true;
                for(int k=0;k<26;k++){
                    if(cnt[k]!=0){
                        ans=false;
                        break;
                    }
                }
                if(ans){
                    break;
                }
            }
        }
        return ans;
    }
};