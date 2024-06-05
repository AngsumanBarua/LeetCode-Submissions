class Solution {
public:
    string clearStars(string s) {
        int n=s.length();
        vector <vector <int>> v(26);
        bool fg[n+1];
        memset(fg,true,sizeof(fg));
        int l=27;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                fg[i]=false;
                //cout << v[l][v[l].size()-1] << endl;
                fg[v[l][v[l].size()-1]]=false;
                v[l].pop_back();
                while(l<26 && v[l].size()==0){
                    l++;
                }
            }
            else{
                l=min(l,s[i]-'a');
                v[s[i]-'a'].push_back(i);
            }
        }
        string ans;
        for(int i=0;i<n;i++){
            if(fg[i]){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};