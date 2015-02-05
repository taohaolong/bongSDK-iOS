//
//  DetailedActivity.h
//  bongSDK
//
//  Created by mario on 15/1/19.
//  Copyright (c) 2015年 Ginshell Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TypeDefs.h"

/**
 *  具体天数据的父类，`DetailedbongActivity`、`DetailedNotbongActivity` 和 `DetailedSleepActivity` 都继承此类
 */
@interface DetailedActivity : NSObject

/**
 *  此段数据的开始时间
 */
@property (strong, nonatomic) NSDate *start;
/**
 *  此段数据的结束时间
 */
@property (strong, nonatomic) NSDate *end;
/**
 *  此段数据的类型，除睡眠、摘下、充电类型外，运动和非运动为两大类数据（即 bong 和非 bong），具体类型可通过子类 `subType` 来确定
 */
@property (assign, nonatomic) bongSDKActivityType type;

@end
