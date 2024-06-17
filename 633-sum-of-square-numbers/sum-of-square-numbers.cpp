class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i=0;
        while(1){
            long long d=c-(i*i);
            if(d<0){
                break;
            }
            long long e=sqrt(d);
            if(e*e==d){
                return true;
            }
            i++;
        }
        return false;
    }
};