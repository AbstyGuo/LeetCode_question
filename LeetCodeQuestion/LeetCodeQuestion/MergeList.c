//
//  MergeList.c
//  LeetCodeQuestion
//
//  Created by 工作 on 2020/2/7.
//  Copyright © 2020 navinfo. All rights reserved.
//

#include "MergeList.h"

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    
    if(l1 == NULL){
        return l2;
    }
    if(l2 == NULL){
        return l1;
    }
    
#if 1
    //解法1 递归
    
    if(l1->val < l2->val){
        l1->next = mergeTwoLists(l1->next,l2);
        return l1;
    }else{
        l2->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
#else
    
    //解法2 归并排序的合并
    
    struct ListNode * result,*cur;
    
    bool firstl1 = l1->val < l2->val;
    cur = firstl1?l1:l2;
    l1 = firstl1?l1->next:l1;
    l2 = firstl1?l2:l2->next;
    result = cur;

    while(l1 && l2){
        if(l1->val < l2->val){
            cur->next = l1;
            l1 = l1->next;
        }
        else{
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1?l1:l2;
    return result;
}
    
#endif
}
