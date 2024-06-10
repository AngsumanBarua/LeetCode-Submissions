class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        int ara[n+1];
        for(int i=0;i<n;i++){
            ara[i]=heights[i];
        }
        sort(ara,ara+n);
        int ans=0;
        for(int i=0;i<n;i++){
            if(ara[i]!=heights[i]){
                ans++;
            }
        }
        return ans;
    }
};