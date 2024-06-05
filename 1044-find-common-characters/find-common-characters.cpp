class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        int ara[27];
        for(int i=0;i<n;i++){
            int ch[26];
            memset(ch,0,sizeof(ch));
            for(int j=0;j<words[i].size();j++){
                ch[words[i][j]-'a']++;
            }
            if(i==0){
                for(int j=0;j<26;j++){
                    ara[j]=ch[j];
                }
            }
            else{
                for(int j=0;j<26;j++){
                    ara[j]=min(ara[j],ch[j]);
                }
            }
        }
        vector <string> ans;
        for(int i=0;i<26;i++){
            for(int j=0;j<ara[i];j++){
                int a=i+'a';
                char c=a;
                string d;
                d.push_back(c);
                ans.push_back(d);
            }
        }
        return ans;
    }
};