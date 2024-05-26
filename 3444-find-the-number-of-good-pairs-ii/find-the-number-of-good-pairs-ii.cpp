class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        int m=nums2.size();
        map <int,long long> mp;
        for(int i=0;i<m;i++){
            mp[nums2[i]]++;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            if(nums1[i]%k==0){
                nums1[i]/=k;
                int sq=sqrt(nums1[i]);
                for(int j=1;j<=sq;j++){
                    if(nums1[i]%j==0){
                        ans+=mp[j];
                        if(nums1[i]/j!=j){
                            ans+=mp[nums1[i]/j];
                        }
                    }
                }
            }
        }
        return ans;
    }
};