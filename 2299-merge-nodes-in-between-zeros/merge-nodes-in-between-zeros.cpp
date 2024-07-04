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
    ListNode* mergeNodes(ListNode* head) {
        bool fg=true;
        ListNode* ans;
        ListNode* mover;
        int sum=0;
        head=head->next;
        while(head!=nullptr){
            if(head->val==0){
                if(fg){
                    ans=new ListNode(sum);
                    fg=false;
                    mover=ans;
                }
                else{
                    ListNode* temp=new ListNode(sum);
                    mover->next=temp;
                    mover=temp;
                }
                sum=0;
            }
            else{
                sum+=head->val;
            }
            head=head->next;
        }
        return ans;
    }
};