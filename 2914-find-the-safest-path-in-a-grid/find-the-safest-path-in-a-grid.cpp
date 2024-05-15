class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return 0;
        }
        if(n>=2 && (grid[0][1]==1 && grid[1][0]==1) || (grid[n-1][n-2]==1 && grid[n-2][n-1]==1)){
            return 0;
        }
        queue <pair <pair<int,int>,int >> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push((make_pair(make_pair(i,j),0)));
                    grid[i][j]=0;
                }
                else{
                    grid[i][j]=-1;
                }
            }
        }
        int r=0;
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int val=q.front().second;
            r=val+2;
            q.pop();
            if(x+1!=n && grid[x+1][y]==-1){
                grid[x+1][y]=val+1;
                q.push((make_pair(make_pair(x+1,y),val+1)));
            }
            if(x-1!=-1 && grid[x-1][y]==-1){
                grid[x-1][y]=val+1;
                q.push((make_pair(make_pair(x-1,y),val+1)));
            }
            if(y+1!=n && grid[x][y+1]==-1){
                grid[x][y+1]=val+1;
                q.push((make_pair(make_pair(x,y+1),val+1)));
            }
            if(y-1!=-1 && grid[x][y-1]==-1){
                grid[x][y-1]=val+1;
                q.push((make_pair(make_pair(x,y-1),val+1)));
            }
        }
        int ans=0;
        int l=0;
        while(l<=r){
            int mid=(l+r)/2;
            bool fg=false;
            map <pair<int,int>,bool> mp;
            stack <pair<int,int>> st;
            st.push(make_pair(0,0));
            mp[make_pair(0,0)]=true;
            if(grid[0][0]>=mid && grid[n-1][n-1]>=mid){
                 while(!st.empty()){
                     pair <int,int> p=st.top();
                     st.pop();
                     if(p.first==n-1 && p.second==n-1){
                         fg=true;
                         ans=max(ans,mid);
                         break;
                     }
                     else{
                         if(p.first+1<n && grid[p.first+1][p.second]>=mid && mp.find(make_pair(p.first+1,p.second))==mp.end()){
                             mp[make_pair(p.first+1,p.second)]=true;
                             st.push(make_pair(p.first+1,p.second));
                         }
                         if(p.first-1>=0 && grid[p.first-1][p.second]>=mid && mp.find(make_pair(p.first-1,p.second))==mp.end()){
                             mp[make_pair(p.first-1,p.second)]=true;
                             st.push(make_pair(p.first-1,p.second));
                         }
                         if(p.second+1<n && grid[p.first][p.second+1]>=mid && mp.find(make_pair(p.first,p.second+1))==mp.end()){
                             mp[make_pair(p.first,p.second+1)]=true;
                             st.push(make_pair(p.first,p.second+1));
                         }
                         if(p.second-1>=0 && grid[p.first][p.second-1]>=mid && mp.find(make_pair(p.first,p.second-1))==mp.end()){
                             mp[make_pair(p.first,p.second-1)]=true;
                             st.push(make_pair(p.first,p.second-1));
                         }
                     }
                 }   
            }
            if(fg){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};