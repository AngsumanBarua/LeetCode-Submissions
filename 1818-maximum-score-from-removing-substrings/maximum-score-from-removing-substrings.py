class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        n=len(s)
        if x<y:
            t=x
            x=y
            y=t
            s=s[::-1]
        a=0;b=0;ans=0
        for i in range(0,n):
            if s[i]=='a':
                a+=1
            elif s[i]=='b':
                if a>=1:
                    a-=1
                    ans+=x
                else:
                    b+=1
            else:
                ans+=min(a,b)*y
                a=0
                b=0
        ans+=min(a,b)*y
        return ans