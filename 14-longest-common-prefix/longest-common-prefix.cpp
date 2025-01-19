class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int l=str.size();
        map <string,int> mp;
        map <string,int> :: iterator it;
        for(int i=0;i<l;i++){
            int sl=str[i].length();
            string s;
            for(int j=0;j<sl;j++){
                s.push_back(str[i][j]);
                mp[s]++;
            }
        }
        string ans;
        for(it=mp.begin();it!=mp.end();it++){
            if(it->second==l && ans.length()<it->first.length()){
                ans=it->first;
            }
        }
        return ans;
    }
};