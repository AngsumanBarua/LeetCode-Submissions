class Solution {
public:
    void dfs(int x,int y,vector <string>& v,vector <vector<bool>>& vis,int n,int l){
        vis[x][y]=true;
        if(x+1<n*3 && !vis[x+1][y] && v[x+1][y]=='0'){
            dfs(x+1,y,v,vis,n,l);
        }
        if(y+1<l*3 && !vis[x][y+1] && v[x][y+1]=='0'){
            dfs(x,y+1,v,vis,n,l);
        }
        if(x-1>=0 && !vis[x-1][y] && v[x-1][y]=='0'){
            dfs(x-1,y,v,vis,n,l);
        }
        if(y-1>=0 && !vis[x][y-1] && v[x][y-1]=='0'){
            dfs(x,y-1,v,vis,n,l);
        }
        return;
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        int l=grid[0].length();
        vector <string> v;
        for(int i=0;i<n;i++){
            string a,b,c;
            for(int j=0;j<l;j++){
                if(grid[i][j]=='/'){
                    a.push_back('0');
                    a.push_back('0');
                    a.push_back('1');
                    b.push_back('0');
                    b.push_back('1');
                    b.push_back('0');
                    c.push_back('1');
                    c.push_back('0');
                    c.push_back('0');
                }
                else if(grid[i][j]=='\\'){
                    a.push_back('1');
                    a.push_back('0');
                    a.push_back('0');
                    b.push_back('0');
                    b.push_back('1');
                    b.push_back('0');
                    c.push_back('0');
                    c.push_back('0');
                    c.push_back('1');
                }
                else{
                    a.push_back('0');
                    a.push_back('0');
                    a.push_back('0');
                    b.push_back('0');
                    b.push_back('0');
                    b.push_back('0');
                    c.push_back('0');
                    c.push_back('0');
                    c.push_back('0');
                }
            }
            v.push_back(a);
            v.push_back(b);
            v.push_back(c);
        }
        vector <vector<bool>> vis(((n*3)+1),vector <bool>(((l*3)+2),false));
        int ans=0;
        for(int i=0;i<n*3;i++){
            for(int j=0;j<l*3;j++){
                if(!vis[i][j] && v[i][j]=='0'){
                    ans++;
                    dfs(i,j,v,vis,n,l);
                }
            }
        }
        return ans;
    }
};