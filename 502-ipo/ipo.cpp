class Solution {
public:
    static bool fun(pair <int,int> a,pair <int,int> b)
    {
        if(a.second!=b.second){
            return a.second<b.second;
        }
        else{
            return a.first>b.first;
        }
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        pair <int,int> vp[n+5];
        for(int i=0;i<n;i++){
            vp[i].first=profits[i];
            vp[i].second=capital[i];
        }
        sort(vp,vp+n,fun);
        for(int i=0;i<n;i++){
            cout << vp[i].first << "   " << vp[i].second << endl;
        }
        priority_queue <int> pq;
        int ind=0;
        while(k){
            while(ind<n && vp[ind].second<=w){
                pq.push(vp[ind].first);
                ind++;
            }
            if(pq.empty()){
                break;
            }
            w+=pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};