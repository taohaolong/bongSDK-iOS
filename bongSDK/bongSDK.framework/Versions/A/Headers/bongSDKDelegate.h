//
//  bongSDKDelegate.h
//  bongSDK
//
//  Created by mario on 15/1/15.
//  Copyright (c) 2015年 Ginshell Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TypeDefs.h"

@class BriefActivity;
@class DetailedDayActivity;
/**
 *  `bongSDKDelegate` 作为 `bongSDK` 的委托协议，处理数据获取、启动、结束等回调信息
 */
@protocol bongSDKDelegate <NSObject>

@optional
/**
 *  bongSDK `run` 回调
 */
- (void)bongSDKDidRun:(bongSDKErrorCode)code;
/**
 *  bongSDK `stop` 回调
 *
 */
- (void)bongSDKDidStop:(bongSDKErrorCode)code;
/**
 *  授权回调
 *
 *  @param errorCode 为 `bongSDKErrorCodeNone` 表示返回成功
 */
- (void)bongSDKDidAutherize:(bongSDKErrorCode)errorCode;
/**
 *  bongSDK 扫描到 bongII 时的回调
 *
 *  目前 bongII 在触摸 Yes! 键时才会被扫描到，
 *  根据 `YesKeyTouchType` 来区分长按、短按，或非触摸类型
 *
 */
- (void)bongSDKDidScanbongIIWithPressYesKey:(YESKeyTouchType)touchType;
/**
 *  手环数据获取状态回调
 *
 *  @param status `bongSDKDataFetchStatus`，状态。返回 `bongSDKDataFetchStatusSucceed`，同步成功，`bongSDKDataFetchStatusFailed` 同步失败
 *  @param error `NSError`，返回更详细的错误信息
 */
- (void)bongSDKDataFetchStatusDidChange:(bongSDKDataFetchStatus)status error:(NSError *)error;
/**
 *  综合数据回调
 *
 *  @param activity `BriefActivity` 一天的简明活动数据
 *  @param error    `NSError` 详细错误信息
 */
- (void)bongSDKDidFetchBriefActivity:(BriefActivity *)activity error:(NSError *)error;
/**
 *  详细数据回调，
 *
 *  @param activity `DetailedDayActivity` 一天的详细活动数据
 *  @param error    `NSError` 详细错误信息
 */
- (void)bongSDKDidFetchDetailedDayActivity:(DetailedDayActivity *)activity error:(NSError *)error;

@end
