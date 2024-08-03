class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n=target.size();
        int ara[1003];
        memset(ara,0,sizeof(ara));
        for(int i=0;i<n;i++){
            ara[target[i]]++;
            ara[arr[i]]--;
        }
        for(int i=1;i<=1000;i++){
            if(ara[i]!=0){
                return false;
            }
        }
        return true;
    }
};