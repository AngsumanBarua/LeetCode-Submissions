class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int tf) {
        int n=times.size();
        vector <pair<int,int>> vp(n);
        for(int i=0;i<n;i++){
            vp[i].first=times[i][0];
            vp[i].second=times[i][1];
        }
        sort(vp.begin(),vp.end());
        int lst=0;
        priority_queue <int,vector <int>, greater<int>> pq;
        priority_queue <pair <int,int>,vector <pair <int,int>>, greater<pair <int,int>>> ppq;
        int ans=-1;
        for(int i=0;i<n;i++){
            while(!ppq.empty() && ppq.top().first<=vp[i].first){
                pq.push(ppq.top().second);
                ppq.pop();
            }
            if(!pq.empty()){
                ppq.push({vp[i].second,pq.top()});
                if(vp[i].first==times[tf][0] && vp[i].second==times[tf][1]){
                    ans=pq.top();
                }
                pq.pop();
            }
            else{
                ppq.push({vp[i].second,lst});
                if(vp[i].first==times[tf][0] && vp[i].second==times[tf][1]){
                    ans=lst;
                }
                lst++;
            }
            if(ans!=-1){
                break;
            }
        }
        return ans;
    }
};