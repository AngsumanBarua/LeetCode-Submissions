class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map <string,int> mp;
        int n1=s1.length();
        int n2=s2.length();
        string s;
        for(int i=0;i<n1;i++){
            if(s1[i]==' '){
                mp[s]++;
                s.clear();
            }
            else{
                s.push_back(s1[i]);
            }
        }
        mp[s]++;
        s.clear();
        for(int i=0;i<n2;i++){
            if(s2[i]==' '){
                mp[s]++;
                s.clear();
            }
            else{
                s.push_back(s2[i]);
            }
        }
        mp[s]++;
        vector <string> ans;
        for(auto it:mp){
            if(it.second==1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};