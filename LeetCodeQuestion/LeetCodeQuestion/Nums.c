//
//  Nums.c
//  LeetCodeQuestion
//
//  Created by 工作 on 2020/2/11.
//  Copyright © 2020 navinfo. All rights reserved.
//

#include "Nums.h"

/**
 * 分拆方法，用时140毫秒，两个循环写在一起，用时180+毫秒
 */
int isContain(int * nums,int numsSize,int target,int equal,int startIndex,int * targetIndex){
    for(;startIndex < numsSize;startIndex++){
        if(nums[startIndex] == (target - equal)){
            *targetIndex = startIndex;
            return 1;
        }
    }
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
    int * a = (int * )malloc(2*sizeof(int));
    memset(a,0,2*sizeof(int));
    
    for(int i = 0; i<numsSize;i++){
        int targetIndex = -1;
        if(isContain(nums,numsSize,target,nums[i],i+1,&targetIndex)){
            a[0] = i;
            a[1] = targetIndex;
            *returnSize = 2;
            return a;
        }
    }
    *returnSize = 0;
    return 0;
}

//大神16毫秒解法

typedef struct Node {
    int index;
    int data;
} NODE;

typedef struct HashTable {
    NODE *element;
    int size;
} HASH_TABLE;

HASH_TABLE* HashTableInit(int size)
{
    HASH_TABLE* table;
    
    if (size <= 0) {
        return NULL;
    }
    
    table = (HASH_TABLE *)malloc(sizeof(HASH_TABLE));
    if (table == NULL) {
        return NULL;
    }
    table->size = size;
    
    table->element = (NODE *)malloc(sizeof(NODE) * size);
    if (table->element == NULL) {
        return NULL;
    }
    memset(table->element, 0xff, sizeof(NODE) * size);
    return table;
}

int HashAddrGet(int data, int size)
{
    int addr = data % size;
    return (addr >= 0) ? addr : addr + size;
}

void HashInsert(HASH_TABLE *table, int index, int data)
{
    int addr = HashAddrGet(data, table->size);
    while (table->element[addr].index != -1) {
        addr = (addr + 1) % table->size;
    }
    table->element[addr].index = index;
    table->element[addr].data = data;
    return;
}

NODE* HashFind(HASH_TABLE *table, int data)
{
    int tmp = HashAddrGet(data, table->size);
    int addr = tmp;
    
    do {
        if (table->element[addr].index == -1) {
            return NULL;
        }
        if (table->element[addr].data == data) {
            return &table->element[addr];
        }
        addr = (addr + 1) % table->size;
    } while (addr != tmp);
    return NULL;
}

void HashFree(HASH_TABLE *table) {
    if (table == NULL) {
        return;
    }
    if (table->element != NULL) {
        free(table->element);
    }
    free(table);
}

#define MAX_TABLE_LEN 100000

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i;
    int *rst = NULL;
    HASH_TABLE *table = NULL;
    NODE *node = NULL;
    
    rst = (int *)malloc(sizeof(int) * 2);
    if (rst == NULL) {
        *returnSize = 0;
        return NULL;
    }
    memset(rst, 0, sizeof(int) * 2);
    
    table = HashTableInit(MAX_TABLE_LEN);
    if (table == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    for (i = 0; i < numsSize; i++) {
        node =  HashFind(table, target - nums[i]);
        if (node != NULL) {
            rst[0] = node->index;
            rst[1] = i;
            break;
        }
        
        HashInsert(table, i, nums[i]);
    }
    
    HashFree(table);
    *returnSize = 2;
    return rst;
}
