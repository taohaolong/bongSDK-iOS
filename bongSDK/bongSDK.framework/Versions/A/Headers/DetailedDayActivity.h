//
//  DetailedDayActivity.h
//  bongSDK
//
//  Created by mario on 15/1/19.
//  Copyright (c) 2015年 Ginshell Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DetailedActivity.h"

/**
 *  一天的详细活动数据
 */
@interface DetailedDayActivity : NSObject

/**
 *  该天日期
 */
@property (strong, nonatomic) NSDate *date;
/**
 *  该天活动数据，按时间升序排列。
 *
 *  数据根据类型封装在 `DetailedActivity`（摘下、充电），`DetailedbongActivity`（运动），
 *  `DetailedNotbongActivity`（非运动）以及 `DetailedSleepAcitivty`（睡眠）对象中。
 */
@property (strong, nonatomic) NSArray *detailedActivities;

@end
