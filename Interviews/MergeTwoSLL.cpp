/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        ListNode* curr = l3;
        
        if(l1 == NULL && l2 == NULL) return NULL;
        else if(l1 == NULL && l2 != NULL) return l2;
        else if(l1 != NULL && l2 == NULL) return l1;
        else {
            
            while(l1 != NULL && l2 != NULL) {
                // l1 = 2 4 7 8
                // l2 = 1 3 6
                if(l1->val <= l2->val) {
                    curr->next = l1;
                    l1 = l1->next;
                } else {
                    curr->next = l2;
                    l2 = l2->next;
                }
                curr = curr->next;
            }

            if(l1 != NULL) {
                curr->next = l1;
            }
            
            if(l2 != NULL) {
                 curr->next = l2;
            }
        }
        
        ListNode* temp = l3;
        l3 = l3->next;
        temp->next = NULL;
        delete temp;
        
        return l3;
    }
};
