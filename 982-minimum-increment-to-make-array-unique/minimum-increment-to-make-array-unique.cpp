class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        int ara[100005];
        memset(ara,0,sizeof(ara));
        int mx=0,ans=0;
        for(int i=0;i<n;i++){
            ara[nums[i]]++;
            mx=max(mx,nums[i]);
        }
        for(int i=0;i<=mx;i++){
            if(ara[i]>0){
                ans+=(ara[i]-1);
                ara[i+1]+=(ara[i]-1);
                if(i==mx && ara[i+1]>1){
                    ans+=((ara[i+1]*(ara[i+1]-1))/2);
                }
            }
        }
        return ans;
    }
};