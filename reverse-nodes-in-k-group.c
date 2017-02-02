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
struct ListNode* sub_reverseKGroup(struct ListNode* head, int k) {
        int i, num = 0;
        struct ListNode *temp_p, *pre_p, *now_p, *head_p;

        if(head == NULL || head->next == NULL || head->next->next == NULL){
                return NULL;
        }

        head_p = head;
        while(head_p = head_p->next) 
                num++;
        if(k > num)
                return NULL;

        head_p = head->next;
        pre_p = head_p;
        temp_p = head_p->next;

        for (i = 0; i < k - 1; i++){
                now_p = temp_p;
                temp_p = temp_p->next; //the node
                now_p->next = pre_p;
                pre_p = now_p;
        }

        head_p->next = temp_p; //the first node become the last
        head->next = pre_p; //the last node become the first
        return head_p;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
        struct ListNode true_head;
        struct ListNode *head_p,*tail_p;
        if (k == 0 || k == 1 || head == NULL || head->next == NULL)
                return head;
        true_head.next = head;
        head_p = &true_head;
        while(head_p = sub_reverseKGroup(head_p, k));
        return true_head.next;
}

