import heapq
class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        pq=[]
        heapq.heappush(pq,1)
        seen=set()
        seen.add(1)
        while 1:
            cur=heapq.heappop(pq)
            n-=1
            if n==0:
                return cur
            
            if cur*2 not in seen:
                seen.add(cur*2)
                heapq.heappush(pq,cur*2)
            if cur*3 not in seen:
                seen.add(cur*3)
                heapq.heappush(pq,cur*3)
            if cur*5 not in seen:
                seen.add(cur*5)
                heapq.heappush(pq,cur*5)
        