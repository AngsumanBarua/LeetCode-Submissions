class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;){
            int j=i;
            int cnt=0;
            while(j<n && (arr[j]&1)){
                j++;
                cnt++;
                if(cnt==3){
                    return true;
                }
            }
            if(cnt==0){
                i++;
            }
            else{
                i=j;
            }
        }
        return false;
    }
};