//
//  main.m
//  LeetCodeQuestion
//
//  Created by 工作 on 2020/2/5.
//  Copyright © 2020 navinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PublicClass.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSMutableArray * array = [NSMutableArray arrayWithObjects:@(1),@(1),@(2),@(3), nil];
        NSInteger count = [PublicClass removeDuplicates:array];
        NSLog(@"count = %ld",count);
        NSLog(@"array = %@",array);
    }
    return 0;
}
