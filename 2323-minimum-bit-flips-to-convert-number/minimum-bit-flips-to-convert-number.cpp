class Solution {
public:
    int minBitFlips(int start, int goal) {
        bool a[33],b[33];
        memset(a,false,sizeof(a));
        memset(b,false,sizeof(b));
        int k=0;
        while(start){
            if(start&1){
                a[k]=true;
            }
            k++;
            start/=2;
        }
        k=0;
        while(goal){
            if(goal&1){
                b[k]=true;
            }
            k++;
            goal/=2;
        }
        int ans=0;
        for(int i=0;i<=32;i++){
            if(a[i]!=b[i]){
                ans++;
            }
        }
        return ans;
    }
};