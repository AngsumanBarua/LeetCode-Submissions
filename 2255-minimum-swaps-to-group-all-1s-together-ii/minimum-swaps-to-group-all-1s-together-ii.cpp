class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int one=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                one++;
            }
        }
        if(one==0 || one==n){
            return 0;
        }
        int cur=0;
        for(int i=0;i<one;i++){
            if(nums[i]==1){
                cur++;
            }
        }
        int ans=one-cur;
        for(int i=1;i<n;i++){
            if(i+one<=n){
                if(nums[i+one-1]==1){
                    cur++;
                }
                if(nums[i-1]==1){
                    cur--;
                }
            }
            else{
                if(nums[i+one-n-1]==1){
                    cur++;
                }
                if(nums[i-1]==1){
                    cur--;
                }
            }
            ans=min(ans,one-cur);
            if(!ans){
                break;
            }
        }
        return ans;
    }
};