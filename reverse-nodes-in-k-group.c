/**
 *  *
 *   *  * Definition for singly-linked list.
 *    *
 *     *   * struct ListNode {
 *      *
 *       *    *     int val;
 *        *
 *         *     *     struct ListNode *next;
 *          *
 *           *      * };
 *            *
 *             *       */
//https://leetcode.com/problems/reverse-nodes-in-k-group/
void sub_reverseKGroup(struct ListNode* head, int k, struct ListNode** tail) {
        int i, left = 0;
        struct ListNode *temp_p, *pre_p, *now_p, *head_p;

        if(head == NULL || head->next == NULL || head->next->next == NULL){
                *tail = NULL;
                return;
        }

        head_p = head->next;
        pre_p = head_p;
        temp_p = head_p->next;

LOOP:        
        for (i = 0; i < k - 1 && temp_p != NULL ; i++){
                now_p = temp_p;
                temp_p = temp_p->next; //the node
                now_p->next = pre_p;
                pre_p = now_p;
        }
        head_p->next = temp_p;

        if (i == (k - 1) || left == 1){ //list ok
        }else{ //k is too big
                left = 1;
                head_p = pre_p;
                pre_p = head_p;
                temp_p = head_p->next;
                goto LOOP;
        }
        *tail = head_p;
        head->next = pre_p;
        return;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
        struct ListNode true_head;
        struct ListNode *head_p,*tail_p;
        if (k == 0 || k == 1 || head == NULL || head->next == NULL)
                return head;
        true_head.next = head;
        tail_p = &true_head;
        while(tail_p != NULL){
                head_p = tail_p;
                sub_reverseKGroup(head_p, k, &tail_p);
        }
        return true_head.next;
}

