class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long int cur=1;
        int ind=0,ans=0;
        int sz=nums.size();
        while(cur<=n){
            if(ind<sz && nums[ind]<=cur){
                cur+=nums[ind];
                ind++;
            }
            else{
                cur+=cur;
                ans++;
            }
        }
        return ans;
    }
};