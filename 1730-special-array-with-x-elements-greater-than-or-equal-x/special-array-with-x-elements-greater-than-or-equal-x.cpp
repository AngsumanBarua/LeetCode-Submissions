class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        int val[n+1];
        memset(val,0,sizeof(val));
        for(int i=0;i<n;i++){
            val[min(n,nums[i])]++;
        }
        int cur=0;
        for(int i=n;i>=1;i--){
            cur+=val[i];
            if(cur==i){
                return i;
            }
        }
        return -1;
    }
};