//
//  ArrayQuestion.h
//  LeetCodeQuestion
//
//  Created by 工作 on 2020/2/6.
//  Copyright © 2020 navinfo. All rights reserved.
//

#ifndef ArrayQuestion_h
#define ArrayQuestion_h

#include <stdio.h>
/*
 每日一题第二题
 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 
 示例 1:
 
 输入: [1,2,3,4,5,6,7] 和 k = 3
 输出: [5,6,7,1,2,3,4]
 解释:
 向右旋转 1 步: [7,1,2,3,4,5,6]
 向右旋转 2 步: [6,7,1,2,3,4,5]
 向右旋转 3 步: [5,6,7,1,2,3,4]
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/rotate-array
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
void rotate(int * nums,int numSize,int k);

/*
 每日一题第4题
 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 
 说明:
 
 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 示例:
 
 输入:
 nums1 = [1,2,3,0,0,0], m = 3
 nums2 = [2,5,6],       n = 3
 
 输出: [1,2,2,3,5,6]
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/merge-sorted-array
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);

/*
 每日一题第5题
 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 
 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 
 你可以假设除了整数 0 之外，这个整数不会以零开头。
 
 示例 1:
 
 输入: [1,2,3]
 输出: [1,2,4]
 解释: 输入数组表示数字 123。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/plus-one
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
int* plusOne(int* digits, int digitsSize, int* returnSize);

#endif /* ArrayQuestion_h */
