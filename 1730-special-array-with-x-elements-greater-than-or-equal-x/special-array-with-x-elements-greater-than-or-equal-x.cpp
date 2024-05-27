class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        int val[1002];
        int mx=0;
        memset(val,0,sizeof(val));
        for(int i=0;i<n;i++){
            val[nums[i]]++;
            mx=max(mx,nums[i]);
        }
        int cur=0;
        for(int i=mx;i>=1;i--){
            cur+=val[i];
            if(cur==i){
                return i;
            }
        }
        return -1;
    }
};