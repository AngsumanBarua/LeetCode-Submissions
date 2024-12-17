class Solution {
public:
    int findCircleNum(vector<vector<int>>& isC) {
        int n=isC.size();
        bool vis[n+3];
        memset(vis,false,sizeof(vis));
        int ans=0;
        stack <int> st;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                st.push(i);
                vis[i]=true;
                while(!st.empty()){
                    int cur=st.top();
                    //cout << i << " " << cur << endl;
                    st.pop();
                    for(int j=0;j<n;j++){
                        if(isC[cur][j]==1 && !vis[j]){
                            st.push(j);
                            vis[j]=true;
                        }
                    }
                }
            }
        }
        return ans;
    }
};