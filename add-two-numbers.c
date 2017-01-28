//https://leetcode.com/problems/add-two-numbers/ 
/**
 *
 *  * Definition for singly-linked list.
 *
 *   * struct ListNode {
 *
 *    *     int val;
 *
 *     *     struct ListNode *next;
 *
 *      * };
 *
 *       */

struct ListNode *list_node_new(int x) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->next = NULL;
        node->val = x;
        return node;
}



struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
        struct ListNode* list_p;
        struct ListNode list_head;
        int temp_dig = 0, l1v, l2v;

        list_p = &list_head;
        while(l1 != NULL || l2 != NULL || temp_dig != 0){
                l1v = l1?l1->val:0;
                l2v = l2?l2->val:0;
                temp_dig = temp_dig + l1v + l2v;
                list_p->next = list_node_new(temp_dig%10);
                temp_dig /= 10;
                l1 = l1?l1->next:l1;
                l2 = l2?l2->next:l2;
                list_p = list_p->next;

        };
        return list_head.next;
}
