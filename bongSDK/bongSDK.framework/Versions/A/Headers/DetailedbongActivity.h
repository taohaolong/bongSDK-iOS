//
//  DetailedbongActivity.h
//  bongSDK
//
//  Created by mario on 15/1/19.
//  Copyright (c) 2015年 Ginshell Inc. All rights reserved.
//

#import "DetailedActivity.h"

/**
 *  bong 详细活动数据，包括热身、健走、运动和跑步类型
 */
@interface DetailedbongActivity : DetailedActivity

/**
 *  bong 具体类型
 */
@property (assign, nonatomic) bongSDKActivitybongType subType;
/**
 *  距离，单位为米
 */
@property (assign, nonatomic) double distance;
/**
 *  速度，单位为千米/小时
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
