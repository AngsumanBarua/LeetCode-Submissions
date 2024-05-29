class Solution {
public:
    int numSteps(string s) {
        int n=s.length();
        int ans=0,carry=0;
        for(int i=n-1;i>0;i--){
            if(s[i]=='1' && !carry || s[i]=='0' && carry){
                carry=1;
                ans+=2;
            }
            else{
                ans++;
            }
        }
        return ans+carry;
    }
};