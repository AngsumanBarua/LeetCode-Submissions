class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        long long sum=0;
        int ans=-1;
        for(int i=0;i<n;i++){
            if(chalk[i]>k-sum){
                ans=i;
                break;
            }
            sum+=chalk[i];
        }
        if(ans==-1){
            sum=(k/sum)*sum;
            for(int i=0;i<n;i++){
                if(chalk[i]>k-sum){
                    ans=i;
                    break;
                }
                sum+=chalk[i];
            }
        }
        return ans;
    }
};