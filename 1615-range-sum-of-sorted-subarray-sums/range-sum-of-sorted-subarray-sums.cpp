class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod=1e9+7;
        priority_queue <int> pq;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                pq.push((-1)*sum);
            }
            //cout << sum << endl;
        }
        int cur=1,ans=0;
        while(!pq.empty()){
            if(cur>=left && cur<=right){
                ans+=((-1)*pq.top());
            }
            ans%=mod;
            cur++;
            pq.pop();
            if(cur>right){
                break;
            }
        }
        return ans;
    }
};