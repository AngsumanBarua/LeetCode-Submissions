public class Solution {
    public string ReverseString(string s){
        char[] ara=s.ToCharArray();
        Array.Reverse(ara);
        return new string(ara);
    }
    public int MaximumGain(string s, int x, int y) {
        int n=s.Length;
        if(x<y){
            int t=x;
            x=y;
            y=t;
            s=ReverseString(s);
        }
        int a=0,b=0,ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                a++;
            }
            else if(s[i]=='b'){
                if(a>=1){
                    ans+=x;
                    a--;
                }
                else{
                    b++;
                }
            }
            else{
                ans+=Math.Min(a,b)*y;
                a=0;
                b=0;
            }
        }
        ans+=Math.Min(a,b)*y;
        return ans;
    }
}