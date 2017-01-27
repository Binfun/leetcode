/**
 *
 *  * Return an array of size *returnSize.
 *
 *   * Note: The returned array must be malloced, assume caller calls free().
 *
 *    */
//https://leetcode.com/problems/sliding-window-maximum/
struct sliding_value{
        int num;
        struct sliding_value *prev;
        struct sliding_value *next;
};

struct sliding_index{
        struct sliding_index *next;
        struct sliding_value value;
};


void sort_l(struct sliding_value *head,struct sliding_value *insert){
        struct sliding_value *p;
        struct sliding_value *p1;
        if (head == NULL){
                return;
        }
        for (p = head; p->next != NULL; p = p->next){
                p1 = p->next;
                if (insert->num >= p1->num){
                        p1->prev->next = insert;
                        insert->prev = p1->prev;
                        p1->prev = insert;
                        insert->next = p1;
                        return;
                }
        }
        //The first node(init) , or the smallest and the last node
        p->next = insert;
        insert->prev = p;
        insert->next = NULL;
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
        int i,j;
        int *answer,cnt = 0;
        struct sliding_index *index,index_head,*index_p;//The index point to the context
        struct sliding_value value_head,*value_p;//malloc the slide windows

        index = (struct sliding_index*)malloc(sizeof(struct sliding_index) * k);
        memset(index, 0 , sizeof(struct sliding_index) * k);
        if (numsSize == 0){
                *returnSize = 0;
                return NULL;
        }

        *returnSize = numsSize - (k - 1); //for the return value
        answer = malloc(sizeof(int)*(*returnSize));
        //step 1,init the index struct
        index_head.next = &(index[0]);
        for (i = 0; i < k-1; i++){
                index[i].next = &(index[i+1]);
        }
        //index[k-1].next = NULL;
        //step 2,init the value struct
        for (i = 0; i < k; i++){
                index[i].value.num = nums[i];
        }
        value_head.next = NULL;

        for (i = 0; i < k; i++)
                sort_l(&value_head,&index[i].value);

        answer[cnt] = value_head.next->num;cnt++;
        //step3,loop
        for (i = k; i < numsSize; i++){
                if (k > 1){
                        //1,delete the node from list(the first node and the oldest)
                        value_p = &index_head.next->value;
                        value_p->prev->next = value_p->next;
                        if (value_p->next)
                                value_p->next->prev = value_p->prev;
                        value_p->next = NULL;
                        value_p->prev = NULL;
                        //2,index struct, take the first node(cause the node just be new) to tail(newest node)
                        for (index_p = &index_head; index_p->next != NULL; index_p = index_p->next) //to the last node
                                ;
                        index_p->next = index_head.next;
                        index_head.next = index_head.next->next;
                        index_p->next->next = NULL;
                        //3,value struct get new value,sort and insert to the list
                        index_p->next->value.num = nums[i];
                        sort_l(&value_head,&index_p->next->value);
                        //4,get biggest value
                        answer[cnt] = value_head.next->num;cnt++;
                }else{
                        answer[cnt] = nums[i];cnt++;
                }
        }
        return answer;
}
