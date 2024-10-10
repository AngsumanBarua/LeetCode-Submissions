class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector <int> mx(n);
        mx[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            mx[i]=max(mx[i+1],nums[i]);
        }
        for(int i=0;i<n-1;i++){
            if(nums[i]<=mx[i+1]){
                for(int j=n-1;j>i;j--){
                    if(nums[i]<=nums[j]){
                        ans=max(ans,j-i);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};