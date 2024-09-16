class Solution {
public:
    int findMinDifference(vector<string>& time) {
        int n=time.size();
        vector <int> v;
        for(int i=0;i<n;i++){
            v.push_back(((time[i][0]-'0')*10+(time[i][1]-'0'))*60+((time[i][3]-'0')*10+(time[i][4]-'0')));
        }
        sort(v.begin(),v.end());
        int ans=abs(1440-v[n-1])+(v[0]-0);
        for(int i=1;i<n;i++){
            ans=min(ans,abs(v[i]-v[i-1]));
        }
        return ans;
    }
};