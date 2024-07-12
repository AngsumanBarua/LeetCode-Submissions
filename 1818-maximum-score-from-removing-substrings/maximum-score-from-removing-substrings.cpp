class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n=s.length();
        if(x<y){
            swap(x,y);
            reverse(s.begin(),s.end());
        }
        int ans=0,a=0,b=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                a++;
            }
            else if(s[i]=='b'){
                if(a>0){
                    a--;
                    ans+=x;
                }
                else{
                    b++;
                }
            }
            else{
                ans+=min(a,b)*y;
                a=0;
                b=0;
            }
        }
        ans+=min(a,b)*y;
        return ans;
    }
};