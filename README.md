bongSDK 是 [bong 智能手环](http://bong.cn) [开放平台](http://bong.cn/share/)计划的一部分。

## 功能

- [x] 获取开放授权
- [x] 获取 bong 天数据
- [x] 获取 bongII 的长按、短按广播 
- [x] 同步 bongII 的手环数据并上传至 bong 服务器

## 开发环境

* iOS 7.0+/ Mac OS X 10.9+
* Xcode 6.1
* bong II，固件 1.2.5+

## 安装

将 `bongSDK.framework` 拖入 Xcode 项目中，根据项目目录选择是否勾选 `Copy items if needed` 选项。然后在 `TARGETS` 的 `Build Settings`中，找到 `Other Linker Flags`，加入 `$(OTHER_LDFLAGS) -ObjC`。

bongSDK 需要添加 `AFNetworking`、`JSONModel` 以及 `MBProgressHUD`这三个第三方库的依赖，具体配置可参考 `Example`。

---

## 使用

如果你不了解 bong 的开发平台授权过程，请先移步 [bong 开放平台](https://github.com/Ginshell/bongOpenPlatform/) 阅读相关文档。

### 初始化
```Obj-C
  [bongSDK setAppID:appID appSecret:appSecret appKey:appKey];
```

### 授权

```Obj-C
  if ([bongSDK isAuthorizationValide]) {
    return;
  }
  
  [bongSDK requstAuthorization];
```

### 获取 bong 天数据

```Obj-C
  [bongSDK fetchbongActivityWithDate:[NSDate date] isDetailed:YES];
  // isDetailed，是否返回详细数据
```

### 搜索手环
```Objc-C
  // 添加 bongSDKDelegate
  [bongSDK addDelegate:self];
  // 开启扫描
  [bongSDK run];

  // 用户触摸 bongII 的 Yes! 键后，bongSDK 会回调：
  - (void)bongSDKDidScanbongIIWithPressYesKey:(YESKeyTouchType)touchType {
    // 根据 YESKeyTouchType 可判断用户的触摸是长按、短按或者非指定触摸类型  
  }
```

### 同步手环
```Obj-C
  - (void)bongSDKDidScanbongIIWithPressYesKey:(YESKeyTouchType)touchType {
    // 当搜索到手环时，可以根据自身需要来判断是否调用同步
    [bongSDK fetchbongIIDataWithStartDate:nil endDate:nil];
    // 同步数据可以指定同步起止日期，不指定日期则手环根据记录自动增量同步
  }

  // 手环同步数据的过程回调，
  // status 为 bongSDKDataFetchStatusSucceed 表示同步成功，即同步到数据并上传至服务器
  - (void)bongSDKDataFetchStatusDidChange:(bongSDKDataFetchStatus)status error:(NSError *)error {}
```

### 示例

具体使用可参考示例项目。