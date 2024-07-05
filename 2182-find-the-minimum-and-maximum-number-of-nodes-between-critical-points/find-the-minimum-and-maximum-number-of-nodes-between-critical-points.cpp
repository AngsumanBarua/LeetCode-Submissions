/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector <int> ans,v;
        int i=2;
        int last=head->val,mid,next;
        head=head->next;
        mid=head->val;
        head=head->next;
        int n=0;
        while(head){
            next=head->val;
            if(last>mid && mid<next){
                v.push_back(i);
                n++;
            }
            else if(last<mid && mid>next){
                v.push_back(i);
                n++;
            }
            last=mid;
            mid=next;
            head=head->next;
            i++;
        }
        if(n>=2){
            int mn=v[1]-v[0];
            for(int i=2;i<n;i++){
                mn=min(mn,v[i]-v[i-1]);
            }
            ans.push_back(mn);
            ans.push_back(v[n-1]-v[0]);
        }
        else{
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};