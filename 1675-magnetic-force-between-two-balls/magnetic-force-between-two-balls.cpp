class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int l=0,r=1000000000;
        while(l<=r){
            int mid=((l-r)/2)+r;
            int last=position[0];
            int cur=m-1;
            for(int i=1;i<n;i++){
                if(last+mid<=position[i]){
                    last=position[i];
                    cur--;
                }
                if(cur==0){
                    break;
                }
            }
            if(cur==0){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return l-1;
    }
};