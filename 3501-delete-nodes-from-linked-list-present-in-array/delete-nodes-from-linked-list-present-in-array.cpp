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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n=nums.size();
        unordered_map <int,bool> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=true;
        }
        while(head){
            ListNode* temp=head;
            if(mp.find(temp->val)==mp.end()){
                //cout << temp->val << endl;
                break;
            }
            head=head->next;
            delete temp;
        }
        //cout << head->val << endl;
        ListNode* cur=head->next;
        ListNode* prev=head;
        while(cur!=NULL){
            ListNode* temp=cur;
            cur=cur->next;
            if(mp.find(temp->val)!=mp.end()){
                delete temp;
            }
            else{
                prev->next=temp;
                prev=prev->next;
            }
        }
        prev->next=NULL;
        return head;
    }
};