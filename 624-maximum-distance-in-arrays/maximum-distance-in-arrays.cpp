class Solution {
public:
    int maxDistance(vector<vector<int>>& arrs) {
        int n=arrs.size();
        int a,b;
        for(int i=0;i<n;i++){
            int m=arrs[i].size();
            if(i==0){
                a=arrs[i][m-1];
            }
            else if(i==1){
                b=arrs[i][m-1];
                if(a<b){
                    swap(a,b);
                }
            }
            else{
                if(arrs[i][m-1]>=a){
                    b=a;
                    a=arrs[i][m-1];
                }
                else if(arrs[i][m-1]>b){
                    b=arrs[i][m-1];
                }
            }
        }
        //cout << a << "  " << b << endl;
        int ans=-1e5;
        for(int i=0;i<n;i++){
            int m=arrs[i].size();
            if(arrs[i][m-1]==a){
                ans=max(ans,abs(arrs[i][0]-b));
            }
            else{
                ans=max(ans,abs(arrs[i][0]-a));
            }
        }
        return ans;
    }
};