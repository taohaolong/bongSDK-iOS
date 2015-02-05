//
//  TypeDefs.h
//  bongSDK
//
//  Created by mario on 15/1/15.
//  Copyright (c) 2015年 Ginshell Inc. All rights reserved.
//

#ifndef bongSDK_TypeDefs_h
#define bongSDK_TypeDefs_h

/**
 *  bongSDK 返回码类型
 */
typedef NS_ENUM(int, bongSDKErrorCode){
  /**
   *  无错误
   */
  bongSDKErrorCodeNone,
  /**
   *  配置无效，即 `appID`、`appKey` 等配置无效
   */
  bongSDKErrorCodeInvalidateConfiguration,
  /**
   *  token 无效，需重新调用 `requestAccessTokenWithCallback:` 来获取
   */
  bongSDKErrorCodeInvalidateToken,
  /**
   *  参数错误
   */
  bongSDKErrorCodeParameterError,
  /**
   *  正在
   */
  bongSDKErrorCodeBusy,
  /**
   *  服务器返回未知错误
   */
  bongSDKErrorCodeResponseUnknown,
  /**
   *  bong 标识符错误
   */
  bongSDKErrorCodeInvalidatebongIdentifier,
  /**
   *  蓝牙未打开，需提醒用户开启蓝牙
   */
  bongSDKErrorCodeBLEPowerOff,
  /**
   *  不支持蓝牙低功耗
   */
  bongSDKErrorCodeBLEUnsupported,
  /**
   *  未获取到手环数据
   */
  bongSDKErrorCodeDataFetchNothing,
  /**
   *  网络连接错误
   */
  bongSDKErrorCodeNetworkError,
  /**
   *  请求成功
   */
  bongSDKErrorCodeRequestSuccess = 200,
  /**
   *  请求未授权
   */
  bongSDKErrorCodeReuqestUnAutherized = 401,
  /**
   *  签名错误
   */
  bongSDKErrorCodeRequestSignError = 403,
  /**
   *  越权错误
   */
  bongSDKErrorCodeRequestExceedingAuthority = 405,
  
  /**
   *  服务器内部错误
   */
  bongSDKErrorCodeRequestInternalError = 500,
  /**
   *  服务器返回未知错误
   */
  bongSDKErrorCodeRequestUnknownError = 2001,
  /**
   *  服务器返回错误
   */
  bongSDKErrorCodeRequestUpperLimit = 2002,
  /**
   *  服务器返回错误
   */
  bongSDKErrorCodeRequestLowerLimit = 2003,
  /**
   *  服务器返回错误
   */
  bongSDKErrorCodeRequestInEvent = 2004,
  /**
   *  服务器返回错误
   */
  bongSDKErrorCodeRequestOffEvent = 2005,
  /**
   *  服务器返回错误
   */
  bongSDKErrorCodeRequestDateLimit = 2007,
  /**
   *  服务器返回错误
   */
  bongSDKErrorCodeRequestDataLimit = 2007,
  /**
   *  服务器返回错误
   */
  bongSDKErrorCodeRequestUnbond = 2012,
};

/**
 *  Yes! 键触摸类型
 */
typedef NS_ENUM(int, YESKeyTouchType){
  /**
   *  未定义类型，任意触摸 Yes! 键都可能产生此类型
   */
  YESKeyTouchTypeNone,
  /**
   *  长触摸，Yes! 键灯闪烁两次松开
   */
  YESKeyTouchTypeLong,
  /**
   *  短触摸，Yes! 键灯闪烁一次松开
   */
  YESKeyTouchTypeShort,
};

/**
 *  数据同步状态
 */
typedef NS_ENUM(int, bongSDKDataFetchStatus){
  /**
   *  初始状态
   */
  bongSDKDataFetchStatusNone,
  /**
   *  连接
   */
  bongSDKDataFetchStatusConnecting,
  /**
   *  同步
   */
  bongSDKDataFetchStatusFetching,
  /**
   *  上传
   */
  bongSDKDataFetchStatusUploading,
  /**
   *  成功结果
   */
  bongSDKDataFetchStatusSucceed,
  /**
   *  失败结果
   */
  bongSDKDataFetchStatusFailed,
};

/**
 *  bong 天数据的类型
 */
typedef NS_ENUM(int, bongSDKActivityType){
  /**
   *  无
   */
  bongSDKActivityTypeNone,
  /**
   *  睡眠类型
   */
  bongSDKActivityTypeSleep,
  /**
   *  运动类型
   */
  bongSDKActivityTypebong,
  /**
   *  非运动类型
   */
  bongSDKActivityTypeNotbong,
  /**
   *  摘下类型
   */
  bongSDKActivityTypeTakeOff,
  /**
   *  充电类型（bongII 手环无此类型，但 bongI 用户升级至 bongII 后，其历史数据可能有此类型）
   */
  bongSDKActivityTypeCharge,
};

/**
 *  运动类型数据的具体运动类型
 */
typedef NS_ENUM(int, bongSDKActivitybongType){
  /**
   *  无
   */
  bongSDKActivitybongTypeNone,
  /**
   *  热身
   */
  bongSDKActivitybongTypeWarmUp,
  /**
   *  健走
   */
  bongSDKActivitybongTypeStride,
  /**
   *  运动
   */
  bongSDKActivitybongTypeSport,
  /**
   *  跑步
   */
  bongSDKActivitybongTypeRun,
  /**
   *  游泳
   */
  bongSDKActivitybongTypeSwim,
  /**
   *  自行车
   */
  bongSDKActivitybongTypeCycling
};

/**
 *  非运动类型数据的具体运动类型
 */
typedef NS_ENUM(int, bongSDKActivityNotbongType){
  /**
   *  无
   */
  bongSDKActivityNotbongTypeNone,
  /**
   *  静
   */
  bongSDKActivityNotbongTypeStill,
  /**
   *  散步
   */
  bongSDKActivityNotbongTypeWalk,
  /**
   *  交通工具
   */
  bongSDKActivityNotbongTypeTrans
};

#endif
