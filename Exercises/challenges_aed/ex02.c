#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize) {
    for(int i = 0; i < numsSize; i++){
        int cont = 0;
        for(int j = 0; j < numsSize; j++){
            if(nums[i] == nums[j]){
                cont++;
                // printf("%d\n", cont);
            }
        }    
        
        if(cont >= numsSize/2){
            int *returnSize = malloc(sizeof(int)); 
            *returnSize = nums[i];
            return returnSize;
        }
    }

    free(nums);
    nums = NULL;
}

int main(){
    
    int numsSize;
    scanf("%d", &numsSize);
    int *nums = malloc(numsSize * sizeof(int));


    for(int i = 0; i < numsSize; i++){
        scanf("%d", &nums[i]);
    }

    int *result = majorityElement(nums, numsSize);
    printf("%d\n", result[0]);

    free(result);
    free(nums);
}