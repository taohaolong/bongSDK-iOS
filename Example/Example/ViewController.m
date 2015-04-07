//
//  ViewController.m
//  Example
//
//  Created by mario on 15/1/14.
//  Copyright (c) 2015年 Ginshell Inc. All rights reserved.
//

#import "ViewController.h"
#import <bongSDK/bongSDK.h>

@interface ViewController () <bongSDKDelegate>

@property (weak, nonatomic) IBOutlet UIButton *runButton;
@property (assign, nonatomic) BOOL isRuning;
@property (assign, nonatomic) BOOL isFetching;
@property (weak, nonatomic) IBOutlet UISwitch *activitySwitch;
@property (weak, nonatomic) IBOutlet UILabel *activityLabel;
@property (weak, nonatomic) IBOutlet UISwitch *syncSwitch;
@property (weak, nonatomic) IBOutlet UILabel *syncLabel;

@end

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];

  // bongSDK 版本号
  NSLog(@"bongSDK version: %@", [bongSDK version]);

  // bongSDK 配置，此处替换成自己的配置
  [bongSDK setAppID:@"1419735044202"
          appSecret:@"558860f5ba4546ddb31eafeee11dc8f4"
             appKey:@"7ae31974a95fec07ad3d047c075b11745d8ce989"];
  // 设置开发者环境，即服务器为测试环境
  [bongSDK enableDevelepMode:YES];
  // 添加 bongSDKDelegate
  [bongSDK addDelegate:self];
}

- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}

- (IBAction)didPressRequestButton:(id)sender {
  if ([bongSDK isAuthorizationValide]) {
    UIAlertView *alert =
    [[UIAlertView alloc] initWithTitle:@"已授权" message:nil delegate:nil cancelButtonTitle:@"OK" otherButtonTitles: nil];
    [alert show];
    return;
  }
  
  [bongSDK requstAuthorization];
}

- (IBAction)didPressRunButton:(id)sender {
  if (!self.isRuning) {
    self.runButton.enabled = NO;
    [bongSDK run];
  } else {
    [bongSDK stop];
  }
}

- (IBAction)didPressFetchButton:(id)sender {
  [bongSDK fetchbongActivityWithDate:[NSDate date]
                          isDetailed:self.activitySwitch.isOn];
}

- (IBAction)didChangeActivitySwitch:(id)sender {
  self.activityLabel.text = self.activitySwitch.isOn? @"详细数据" : @"摘要数据";
}

- (IBAction)didChangeSyncSwitch:(id)sender {
  self.syncLabel.textColor = self.activitySwitch.isOn? [UIColor darkTextColor] : [UIColor lightGrayColor];
}

#pragma mark - bongSDKDelegate

- (void)bongSDKDidAutherize:(bongSDKErrorCode)errorCode {
  NSLog(@"授权获取成功 errorCode %d", errorCode);
}

- (void)bongSDKDidRun:(bongSDKErrorCode)code {
  NSLog(@"开始搜索手环 %d", code);
  self.runButton.enabled = YES;
  
  if (code == bongSDKErrorCodeNone) {
    self.isRuning = YES;
    [self.runButton setTitle:@"停止搜索" forState:UIControlStateNormal];
  }
}

- (void)bongSDKDidStop:(bongSDKErrorCode)code {
  NSLog(@"手环搜索停止 %d", code);
  if (code == bongSDKErrorCodeNone) {
    self.isRuning = NO;
    [self.runButton setTitle:@"搜索手环" forState:UIControlStateNormal];
    self.isFetching = NO;
  }
}

- (void)bongSDKDidScanbongIIWithPressYesKey:(YESKeyTouchType)touchType {
  if (touchType == YESKeyTouchTypeLong) {
    NSLog(@"长按");
  } else if (touchType == YESKeyTouchTypeShort) {
    NSLog(@"短按");
  } else {
    NSLog(@"搜索到设备");
  }
  
  if (self.isFetching || !self.syncSwitch.isOn) {
    return;
  }
  self.isFetching = YES;
  
  NSLog(@"开始获取手环数据");
  NSDate *endDate = [NSDate date];
  // 1.2.5 固件以上，手环最多存储 7 天数据；1.2.5 固件以下此接口不可用
  [bongSDK fetchbongIIDataWithStartDate:[NSDate dateWithTimeInterval:-10*60 sinceDate:endDate] endDate:nil];
}

- (void)bongSDKDataFetchStatusDidChange:(bongSDKDataFetchStatus)status error:(NSError *)error {
  NSLog(@"手环数据同步状态更新 %d error %@", status, error);
  if (status == bongSDKDataFetchStatusSucceed ||
      status == bongSDKDataFetchStatusFailed) {
    self.isFetching = NO;
  }
}

- (void)bongSDKDidFetchBriefActivity:(BriefActivity *)activity error:(NSError *)error {
  NSLog(@"获取到摘要天数据 %@ error %@", activity, error);
}

- (void)bongSDKDidFetchDetailedDayActivity:(DetailedDayActivity *)activity error:(NSError *)error {
  NSLog(@"获取到详细天数据 %@ error %@", activity, error);
}

@end
