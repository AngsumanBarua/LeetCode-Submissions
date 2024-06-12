class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        long long ara[n+3];
        int mod=1000000007;
        for(int j=0;j<n;j++){
            ara[j]=1;
            //cout << ara[j] << "   ";
        }
        //cout << endl;
        for(int i=1;i<=k;i++){
            for(int j=1;j<n;j++){
                ara[j]+=ara[j-1];
                ara[j]%=mod;
                //cout << ara[j] << "  ";
            }
            //cout << endl;
        }
        return ara[n-1];
    }
};