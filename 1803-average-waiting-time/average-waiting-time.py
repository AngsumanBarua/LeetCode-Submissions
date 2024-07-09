class Solution:
    def averageWaitingTime(self, cus: List[List[int]]) -> float:
        n=len(cus)
        tot=0;cur=0
        for i in range(n):
            if cur<cus[i][0]:
                cur=cus[i][0]+cus[i][1]
                tot+=cus[i][1]
            else:
                cur+=cus[i][1]
                tot+=(cur-cus[i][0])

        return tot/n