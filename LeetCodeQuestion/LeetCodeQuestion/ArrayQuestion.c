//
//  ArrayQuestion.c
//  LeetCodeQuestion
//
//  Created by 工作 on 2020/2/6.
//  Copyright © 2020 navinfo. All rights reserved.
//

#include "ArrayQuestion.h"

void reverse(int * nums,int start,int end);

void rotate(int * nums,int numsSize,int k){
    if(!nums || numsSize == 0)
        return;
    k = k % numsSize;
#if 0
    //解法1.
    int x = 0;
    while (x<k) {
        int temp = nums[numsSize - 1];
        for (int i = numsSize-1; i>0; i--) {
            nums[i] = nums[i-1];
        }
        nums[0] = temp;
        x++;
    }
#elif 1
    //解法2.
    k%=numsSize;
    reverse(nums,0,numsSize-1);
    reverse(nums,0,k-1);
    reverse(nums,k,numsSize-1);
#else
    //解法3.
    int cnt = 0, start = 0, cur;
    int prev, next, tmp;
    while(cnt < numsSize){
        cur = start;
        prev = nums[start];
        do{
            next = (cur + k) % numsSize;
            tmp = nums[next];
            nums[next] = prev;
            prev = tmp;
            cur = next;
            cnt++;
        }while(start != cur);
        start++;
    }
#endif
}

void reverse(int * nums,int start,int end){
    int temp = 0;
    while(start < end){
        temp = nums[start];
        nums[start++]=nums[end];
        nums[end--]=temp;
    }
}
