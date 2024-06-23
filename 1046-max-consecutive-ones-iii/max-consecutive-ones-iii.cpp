class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0;
        int ans=0,zero=0;
        while(r<n){
            if(nums[r]==1 && zero<=k){
                ans=max(ans,r-l+1);
                r++;
            }
            else if(nums[r]==0 && zero+1<=k){
                ans=max(ans,r-l+1);
                r++;
                zero++;
            }
            else if(l==r){
                if(nums[r]==0){
                    zero++;
                }
                r++;
            }
            else{
                if(nums[l]==0){
                    zero--;
                }
                l++;
            }
        }
        return ans;
    }
};