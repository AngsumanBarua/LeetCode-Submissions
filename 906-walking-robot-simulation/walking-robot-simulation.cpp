class Solution {
public:
    long long robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n=obstacles.size();
        map <long long,bool> mp;
        for(int i=0;i<n;i++){
            mp[((((long long)obstacles[i][0]+60001)*60001)+((long long)obstacles[i][1]+60001))]=true;
        }
        n=commands.size();
        int cur=1;
        long long x=0,y=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(commands[i]==-1){
                cur--;
            }
            else if(commands[i]==-2){
                cur++;
            }
            else{
                if(cur==1){
                    while(commands[i]){
                        if(mp.find(((((long long)x+60001)*60001)+(long long)y+60001+1))!=mp.end()){
                            break;
                        }
                        y++;
                        commands[i]--;
                    }
                }
                else if(cur==4){
                    while(commands[i]){
                        if(mp.find(((((long long)x+60001+1)*60001)+(long long)y+60001))!=mp.end()){
                            break;
                        }
                        x++;
                        commands[i]--;
                    }
                }
                else if(cur==3){
                    while(commands[i]){
                        if(mp.find(((((long long)x+60001)*60001)+(long long)y+60001-1))!=mp.end()){
                            break;
                        }
                        y--;
                        commands[i]--;
                    }
                }
                else{
                    while(commands[i]){
                        if(mp.find(((((long long)x+60001-1)*60001)+(long long)y+60001))!=mp.end()){
                            break;
                        }
                        x--;
                        commands[i]--;
                    }
                }
                //cout << x << "  " << y << endl;
                ans=max(ans,(x*x)+(y*y));
            }
            if(cur==0){
                cur=4;
            }
            else if(cur==5){
                cur=1;
            }
            //cout << i << "        " << cur << endl;
        }
        return ans;
    }
};