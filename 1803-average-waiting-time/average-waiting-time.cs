public class Solution {
    public double AverageWaitingTime(int[][] cus) {
        int n=cus.Length;
        long tot=0,cur=0;
        for(int i=0;i<n;i++){
            if(cur<cus[i][0]){
                cur=cus[i][0]+cus[i][1];
                tot+=cus[i][1];
            }
            else{
                cur+=cus[i][1];
                tot+=(cur-cus[i][0]);
            }
        }
        double ans=(double)tot/(double)n;
        return ans; 
    }
}