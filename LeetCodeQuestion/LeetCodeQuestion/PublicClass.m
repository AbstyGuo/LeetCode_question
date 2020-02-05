//
//  Day01.m
//  LeetCodeQuestion
//
//  Created by 工作 on 2020/2/5.
//  Copyright © 2020 navinfo. All rights reserved.
//

#import "PublicClass.h"

@implementation PublicClass

+ (NSInteger)removeDuplicates:(NSMutableArray *)array{
    NSInteger i = 0;
    for(int j = 1;j<array.count;j++){
        if ([array[i] isNotEqualTo:array[j]]) {
            array[++i] = array[j];
        }
    }
    return i+1;
}

@end
