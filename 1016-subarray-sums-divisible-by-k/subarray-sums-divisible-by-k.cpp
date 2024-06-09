class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map <int,int> mp;
        int cur=0,ans=0;
        for(int i=0;i<n;i++){
            cur+=nums[i];
            int mod=cur%k;
            if(cur<0){
                int mul=(cur*-1);
                mul/=k;
                mul++;
                mod=((mul*k)+cur)%k;
            }
            if(mod==0){
                ans++;
            }
            if(mp.find(mod)!=mp.end()){
                ans+=mp[mod];
            }
            mp[mod]++;
        }
        return ans;
    }
};