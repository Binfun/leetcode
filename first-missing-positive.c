//https://leetcode.com/problems/first-missing-positive/
int firstMissingPositive(int* nums, int numsSize) {
        int i, temp;
        for (i = 0; i < numsSize; i++){
                while (nums[i] <= numsSize && nums[i] > 0 && nums[nums[i] - 1] != nums[i]){
                        temp = nums[i];
                        nums[i] = nums[nums[i] - 1];
                        nums[temp - 1] = temp;
                }
        }
        printf("what!");
        for (i = 0; i < numsSize; i++){
                if (nums[i] != i + 1)
                        return (i + 1);
        }
        return (numsSize + 1);
}

