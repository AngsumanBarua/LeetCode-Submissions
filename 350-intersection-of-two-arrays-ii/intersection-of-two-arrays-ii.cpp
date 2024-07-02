class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        map <int,int> mp1,mp2;
        for(int i=0;i<n;i++){
            mp1[nums1[i]]++;
        }
        for(int i=0;i<m;i++){
            mp2[nums2[i]]++;
        }
        vector <int> ans;
        for(int i=0;i<=1000;i++){
            for(int j=0;j<min(mp1[i],mp2[i]);j++){
                ans.push_back(i);
            }
        }
        return ans;
    }
};