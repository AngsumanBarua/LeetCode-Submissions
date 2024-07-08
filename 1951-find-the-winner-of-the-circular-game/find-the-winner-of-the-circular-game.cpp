class Solution {
public:
    int findTheWinner(int n, int k) {
        bool fg[n+1];
        memset(fg,false,sizeof(fg));
        int m=1;
        for(int i=1;i<n;i++){
            int l=k;
            while(l){
                if(!fg[m]){
                    l--;
                }
                if(l==0){
                    fg[m]=true;
                }  
                else{
                    m++;
                    if(m==n+1){
                        m=1;
                    }
                }
            }
            
        }
        int ans;
        for(int i=1;i<=n;i++){
            if(!fg[i]){
                ans=i;
            }
        }
        return ans;
    }
};