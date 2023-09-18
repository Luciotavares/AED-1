#include <stdio.h>
#include <stdlib.h>
int *topKFrequent(int *nums, int numsSize, int k, int *returnSize) {
 

  int *freq = (int *)malloc(sizeof(int) * k);
  int cont = 0;
  int j = 0;

 
  for (int i = 0; i < numsSize; i++) {
   
    if (i > 0 && nums[i] == nums[i - 1]) {
      cont++;
    } else {
      cont = 1;
    }

    if (cont >= k) {
      freq[j] = nums[i];
      j++;
    }
  }

  int *res = (int *)malloc(sizeof(int) * j);
  for (int i = 0; i < j; i++) {
    res[i] = freq[i];
  }

  
  *returnSize = j;
  return res;
 
}
int main() {

  int nums[] = {1, 1, 1, 2, 2, 3};
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int k = 2;
  int returnSize;

 
  int *res = topKFrequent(nums, numsSize, k, &returnSize);

  for (int i = 0; i < returnSize; i++) {
    printf("%d\n", res[i]);
  }

  
  free(res);
  
  return 0;
}
