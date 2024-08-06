class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        int cnt[27];
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++){
            cnt[word[i]-'a']++;
        }
        sort(cnt,cnt+26,greater <int> ());
        int ans=0;
        for(int i=0;i<=25;i++){
            if(i<8){
                ans+=cnt[i];
            }
            else if(i<16){
                ans+=(cnt[i]*2);
            }
            else if(i<24){
                ans+=(cnt[i]*3);
            }
            else{
                ans+=(cnt[i]*4);
            }
        }
        return ans;
    }
};