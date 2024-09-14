class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int mx=0,ans=0;
        for(int i=0;i<n;){
            int j=i;
            int cnt=0;
            while(j<n && nums[i]==nums[j]){
                cnt++;
                j++;
            }
            if(nums[i]>mx){
                mx=nums[i];
                ans=cnt;
            }
            else if(nums[i]==mx){
                ans=max(cnt,ans);
            }
            i=j;
        }
        return ans;
    }
};