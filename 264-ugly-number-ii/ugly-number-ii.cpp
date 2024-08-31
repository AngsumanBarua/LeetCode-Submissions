class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue <long long,vector <long long>, greater <long long>> pq;
        pq.push(1);
        map <long long,bool> mp;
        while(1){
            long long cur=pq.top();
            pq.pop();
            n--;
            if(n==0){
                return cur;
            }
            if(mp.find(cur*2)==mp.end()){
                pq.push(cur*2);
                mp[cur*2]=true;
            }
            if(mp.find(cur*3)==mp.end()){
                pq.push(cur*3);
                mp[cur*3]=true;
            }
            if(mp.find(cur*5)==mp.end()){
                pq.push(cur*5);
                mp[cur*5]=true;
            }
        }
    }
};