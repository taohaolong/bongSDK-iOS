//
//  DetailedSleepActivity.h
//  bongSDK
//
//  Created by mario on 15/1/19.
//  Copyright (c) 2015年 Ginshell Inc. All rights reserved.
//

#import "DetailedActivity.h"

/**
 *  睡眠详细数据
 */
@interface DetailedSleepActivity : DetailedActivity

/**
 *  深睡眠分钟数
 */
@property (assign, nonatomic) int deepSleepMinutes;
/**
 *  浅睡眠分钟数
 */
@property (assign, nonatomic) int lightSleepMinutes;
/**
 *  清醒分钟数
 */
@property (assign, nonatomic) int wakeMinutes;
/**
 *  睡眠中断次数
 */
@property (assign, nonatomic) int interruptTimes;
/**
 *  睡眠评分。0.0 ~ 5.0，最小单位 0.5
 */
@property (assign, nonatomic) double score;

@end
