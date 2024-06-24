class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        deque <int> dq1,dq2;
        int l=0,ans=0;
        for(int i=0;i<n;i++){
            while(!dq1.empty() && dq1.back()<nums[i]){
                dq1.pop_back();
            }
            dq1.push_back(nums[i]);
            while(!dq2.empty() && dq2.back()>nums[i]){
                dq2.pop_back();
            }
            dq2.push_back(nums[i]);
            while(abs(dq1.front()-dq2.front())>limit){
                if(!dq1.empty() && dq1.front()==nums[l]){
                    dq1.pop_front();
                }
                if(!dq2.empty() && dq2.front()==nums[l]){
                    dq2.pop_front();
                }
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};