//
//  BriefActivity.h
//  bongSDK
//
//  Created by mario on 15/1/19.
//  Copyright (c) 2015年 Ginshell Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  天综合数据，当天数据的摘要信息
 */
@interface BriefActivity : NSObject

/**
 *  日期
 */
@property (strong, nonatomic) NSDate *date;
/**
 *  该日运动消耗的热量总和，单位是千焦
 */
@property (assign, nonatomic) double calories;
/**
 *  该日的移动的步数综合，单位是步
 */
@property (assign, nonatomic) int steps;
/**
 *  该日移动的总距离，单位是米
 */
@property (assign, nonatomic) double distance;
/**
 *  该日的静坐时间总和，单位是秒
 */
@property (assign, nonatomic) int stillTime;
/**
 *  深睡眠时长,单位是分钟
 */
@property (assign, nonatomic) int deepSleepMinutes;
/**
 *  睡眠次数
 */
@property (assign, nonatomic) int sleepTimes;
/**
 *  该日数据是否完整。 0:不完整 1:完整 -1:数据丢失
 */
@property (assign, nonatomic) int complete;

@end
