int removeElement(int* nums, int numsSize, int val) {
   int i,size=0;
   for(i=0;i<numsSize;i++){
    if(nums[i]!=val)
   nums[size++]=nums[i]; 
   }
   return size;
}