class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        stack <pair<int,int>> st;
        st.push(make_pair(nums[n-1],n-1));
        for(int i=n-2;i>=0;i--){
            if(st.top().first<nums[i]){
                st.push(make_pair(nums[i],i));
            }
        }
        for(int i=0;i<n;i++){
            stack <pair<int,int>> temp;
            while(!st.empty() && st.top().first>=nums[i]){
                ans=max(ans,st.top().second-i);
                temp.push(make_pair(st.top().first,st.top().second));
                st.pop();
            }
            while(!temp.empty()){
                st.push(make_pair(temp.top().first,temp.top().second));
                temp.pop();
            }
            while(!st.empty() && st.top().second<=i){
                st.pop();
            }
        }
        return ans;
    }
};