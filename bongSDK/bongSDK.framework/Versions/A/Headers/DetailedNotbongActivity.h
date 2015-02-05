//
//  DetailedNotbongActivity.h
//  bongSDK
//
//  Created by mario on 15/1/19.
//  Copyright (c) 2015年 Ginshell Inc. All rights reserved.
//

#import "DetailedActivity.h"

/**
 *  非 bong 活动数据，包括静、散步等
 */
@interface DetailedNotbongActivity : DetailedActivity

/**
 *  非 bong 具体类型
 */
@property (assign, nonatomic) bongSDKActivityNotbongType subType;
/**
 *  活跃状态持续时间，单位为秒
 */
@property (assign, nonatomic) int activeSeconds;
/**
 *  非活跃状态持续时间，单位为秒
 */
@property (assign, nonatomic) int nonActiveSeconds;
/**
 *  距离，单位为米
 */
@property (assign, nonatomic) double distance;
/**
 *  速度，单位千米/小时
 */
@property (assign, nonatomic) double speed;
/**
 *  消耗热量，单位是千焦
 */
@property (assign, nonatomic) double calories;
/**
 *  步数
 */
@property (assign, nonatomic) int steps;

@end
