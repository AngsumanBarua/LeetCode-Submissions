class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        bool ans=false;
        if(n%groupSize==0){
            sort(hand.begin(),hand.end());
            unordered_map <int,int> mp;
            for(int i=0;i<n;i++){
                mp[hand[i]]++;
            }
            ans=true;
            for(int i=0;i<n;i++){
                if(mp[hand[i]]){
                    mp[hand[i]]--;
                    int cur=hand[i]+1;
                    for(int j=1;j<groupSize;j++){
                        if(mp[cur]){
                            mp[cur]--;
                        }
                        else{
                            ans=false;
                            break;
                        }
                        cur++;
                    }
                }
                if(!ans){
                    break;
                }
            }
        }
        return ans;
    }
};