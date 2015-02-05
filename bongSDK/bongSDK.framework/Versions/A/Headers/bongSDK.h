//
//  bongSDK.h
//  bongSDK
//
//  Created by mario on 15/1/14.
//  Copyright (c) 2015年 Ginshell Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TypeDefs.h"
#import "bongSDKDelegate.h"

/**
 * 为正常使用 category ，需要设置 Other Linker Flags: $(OTHER_LDFLAGS) -ObjC
 * 参照：
 *  https://developer.apple.com/library/mac/qa/qa1490/_index.html
 */


/**
 *  bongSDK 是 bong iOS 开放平台的开发工具，
 *  更多信息可访问： https://github.com/Ginshell/bongOpenPlatform
 */
@interface bongSDK : NSObject

/**
 *  bongSDK 版本号
 */
+ (NSString *)version;

/**
 *  初始化 bongSDK
 *
 *  初始化时需配置 bongSDK 的必要信息，具体可参考：
 *  https://github.com/Ginshell/bongOpenPlatform/blob/master/docs/signup.md
 *
 *  @param appID     应用在 bong 开放平台注册的 ID
 *  @param appSecret 应用在 bong 开放平台获取的 secret
 *  @param appKey    应用在 bong 开发平台获取的 key
 */
+ (void)setAppID:(NSString *)appID appSecret:(NSString *)appSecret appKey:(NSString *)appKey;
/**
 *  是否开启开发者模式
 *
 *  bong 开放平台拥有测试环境、正式环境
 *  开发者模式对应 bong 开发平台的测试环境
 *
 *  @param enabled YES，开启； NO，关闭。默认关闭，即正式环境
 */
+ (void)enableDevelepMode:(BOOL)enabled;
/**
 *  是否开启调试模式，开启则输出调试日志
 *
 *  @param enabled YES，开启； NO，关闭。默认关闭
 */
+ (void)enableDebugMode:(BOOL)enabled;
/**
 *  添加 `bongSDKDelegate`
 */
+ (void)addDelegate:(id <bongSDKDelegate>)delegate;
/**
 *  移除 `bongSDKDelegate`
 */
+ (void)removeDelegate:(id <bongSDKDelegate>)delegate;
/**
 *  获取开放平台授权
 *
 */
+ (void)requstAuthorization;
/**
 * 开发平台授权是否有效
 *
 */
+ (BOOL)isAuthorizationValide;
/**
 *  bongSDK 开启扫描
 *
 *  bongII 的同步功能需要保持蓝牙开启并持续扫描，
 *  当扫描到广播数据时，会回调 `bongSDKDidScanbongIIWithPressYesKey:`，
 *  此时，可以根据返回的按键类型做处理或直接同步数据。
 *
 *  该方法运行结果可在委托方法 `bongSDKDidRun:` 获取。
 */
+ (void)run;
/**
 *  bongSDK 关闭扫描
 */
+ (void)stop;
/**
 *  同步手环数据，并上传服务器
 *
 *  手环同步可以传 `start` 和 `end` 两个日期，来指定同步哪一个时间段的数据。
 *  手环目前可以存储 7 天数据
 *
 *  @param start 起始日期
 *  @param end   结束日期
 */
+ (void)fetchbongIIDataWithStartDate:(NSDate *)start endDate:(NSDate *)end;
/**
 *  获取 bong 的天活动数据
 *
 *  @param date       获取日期
 *  @param isDetailed 为 `YES`，返回详细数据；`NO`，返回摘要数据
 */
+ (void)fetchbongActivityWithDate:(NSDate *)date isDetailed:(BOOL)isDetailed;

@end
