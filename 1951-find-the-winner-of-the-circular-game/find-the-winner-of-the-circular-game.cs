public class Solution {
    public int FindTheWinner(int n, int k) {
        bool[] fg=new bool[n+1];
        int m=1;
        for(int i=1;i<n;i++){
            int l=k;
            while(l>0){
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
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!fg[i]){
                ans=i;
            }
        }
        return ans;
    }
}