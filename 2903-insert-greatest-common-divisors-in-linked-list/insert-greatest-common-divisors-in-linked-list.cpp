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
    int gcd(int A,int B)
    {
        while(B){
            int mod=A%B;
            A=B;
            B=mod;
        }
        return A;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* last=head;
        ListNode* temp=last;
        temp=temp->next;
        while(temp){
            last->next=new ListNode(gcd(temp->val,last->val),temp);
            last=last->next;
            last=last->next;
            temp=temp->next;
        }
        return head;
    }
};