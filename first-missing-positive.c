//https://leetcode.com/problems/first-missing-positive/
int firstMissingPositive(int* nums, int numsSize) {
        int i;
        int *oknum;
        oknum = malloc(sizeof(int)*numsSize);
        memset(oknum, 0, sizeof(int)*numsSize);
        for(i = 0; i < numsSize; i++){
                if(nums[i] > 0 && nums[i] <= numsSize ){
                        oknum[nums[i] - 1] = 1;
                }
        }

        for(i = 0; i < numsSize; i++){
                if(oknum[i] == 0){
                        return (i + 1);
                }
        }
        return (numsSize + 1);
}
