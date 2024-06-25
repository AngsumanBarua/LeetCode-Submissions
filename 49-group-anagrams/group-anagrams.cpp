class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map <string,vector <int>> mp;
        unordered_map <string,vector <int>> :: iterator it;
        for(int i=0;i<n;i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(i);
        }
        vector<vector<string>> ans;
        for(it=mp.begin();it!=mp.end();it++){
            int l=mp[it->first].size();
            vector <string> vv;
            for(int i=0;i<l;i++){
                vv.push_back(strs[mp[it->first][i]]);
            }
            ans.push_back(vv);
        }
        return ans;
    }
};