class Solution {
public:
    bool dfs(int x,int y,vector<vector<char>>& board, vector <vector <bool>>& vis,int n,int m,vector <pair<int,int>>& v){
        vis[x][y]=true;
        v.push_back({x,y});
        bool a=false,b=false,c=false,d=false;
        if(x+1<n && board[x+1][y]=='O' && !vis[x+1][y]){
            a=dfs(x+1,y,board,vis,n,m,v);
        }
        if(y+1<m && board[x][y+1]=='O' && !vis[x][y+1]){
            b=dfs(x,y+1,board,vis,n,m,v);
        }
        if(x-1>=0 && board[x-1][y]=='O' && !vis[x-1][y]){
            c=dfs(x-1,y,board,vis,n,m,v);
        }
        if(y-1>=0 && board[x][y-1]=='O' && !vis[x][y-1]){
            d=dfs(x,y-1,board,vis,n,m,v);
        }
        if(x+1==n || x-1<0 || y+1==m || y-1==-1){
            return true;
        }
        return a || b ||  c|| d;
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector <vector <bool>> vis(n,vector <bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    //cout << i << " " << j << endl;
                    vector <pair<int,int>> v;
                    if(!dfs(i,j,board,vis,n,m,v)){
                        int sz=v.size();
                        for(int k=0;k<sz;k++){
                            //cout << v[k].first << "  " << v[k].second << endl;
                            board[v[k].first][v[k].second]='X';
                        }
                    }
                }
            }
        }
        return;
    }
};