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



void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    
    //解题思路1：
    //拿到 两个的总数
    int i = m-- + n-- -1;
    //循环设置最后一个数
    while(i >= 0){
        if(m>=0 && n >= 0)
            nums1[i--] = nums1[m] > nums2[n]? nums1[m--]:nums2[n--];
        
        else if(m < 0)
            nums1[i--] = nums2[n--];
        
        else
            break;
    }
    
    
    //解析思路2
    //遍历数组2
    for(int i=0;i<n;i++){
        //拿到数组1的个数
        int j=m-1;
        
        //从后向前遍历数组1
        for(;j>=0;j--){
            
            //如果数组1的数大于，数组1的元素后移1位
            if(nums2[i]<nums1[j]){
                nums1[j+1]=nums1[j];
            }else{
                //找到了对应的位置j
                break;
            }
        }
        //将对应位置的值填入
        nums1[j+1]=nums2[i];
        //更新总数
        m++;
    }
}
