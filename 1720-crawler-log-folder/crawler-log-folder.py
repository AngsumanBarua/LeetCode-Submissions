class Solution:
    def minOperations(self, logs: List[str]) -> int:
        n=len(logs)
        cur=0;
        for i in range(n):
            m=len(logs[i])
            if m==3 and logs[i][0]=='.' and logs[i][1]=='.':
                if(cur!=0):
                    cur-=1;
                
            elif m==2 and logs[i][0]!='.' or m>=3:
                cur+=1;
        return cur