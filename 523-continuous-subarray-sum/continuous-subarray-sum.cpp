class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long cur=0;
        map <long long,int> mp;
        bool ans=false;
        for(int i=0;i<n;i++){
            cur+=nums[i];
            int mod=cur%k;
            if((mod==0 && i>=1) || mp.find(mod)!=mp.end() && mp[mod]+2<=i){
                ans=true;
                break;
            }
            if(mp.find(mod)==mp.end()){
                mp[mod]=i;
            }
        }
        return ans;
    }
};