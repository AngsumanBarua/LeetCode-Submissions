class Solution {
public:
    int numWaterBottles(int numB, int numE) {
        int ans=numB;
        int mod=0;
        while(numB){
            ans+=((numB+mod)/numE);
            int t=(numB+mod)%numE;
            numB=(numB+mod)/numE;
            mod=t;
        }
        return ans;
    }
};