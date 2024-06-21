class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int ara[n+1];
        int cur=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                cur+=customers[i];
            }
            ara[i]=cur;
        }
        int pre=0;
        cur=0;
        for(int i=0;i<minutes;i++){
            cur+=customers[i];
        }
        int ans=cur+(ara[n-1]-ara[minutes-1]);
        for(int i=minutes;i<n;i++){
            pre+=customers[i-minutes];
            cur+=customers[i];
            ans=max(ans,cur-pre+(ara[n-1]-ara[i])+ara[i-minutes]);
        }
        return ans;
    }
};