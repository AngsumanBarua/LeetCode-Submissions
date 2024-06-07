class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n=dictionary.size();
        unordered_map <string,bool> mp;
        for(int i=0;i<n;i++){
            mp[dictionary[i]]=true;
        }
        string s,ans;
        bool fg=true;
        int l=sentence.length();
        for(int i=0;i<l;i++){
            if(sentence[i]==' '){
                s.clear();
                ans.push_back(sentence[i]);
                fg=true;
            }
            else{
                if(fg){
                    s.push_back(sentence[i]);
                    ans.push_back(sentence[i]);
                    if(mp.find(s)!=mp.end()){
                        fg=false;
                    }
                }
            }
        }
        return ans;
    }
};