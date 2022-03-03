# ame-ktv-sdk

## 目录结构说明

本目录包含安卓， iOS 版 ame SDK 的Demo 源代码，主要演示接口如何调用以及最基本的功能。

```
├─ Android //安卓工程 
|  ├─ SDK   
|  ├─ Demo
├─ iOS // iOS工程
|  ├─ SDK   
|  |  ├─ TXCopyrightedMedia.framework 
|  ├─ Demo  //iOS ame的Demo
|  ├─ README.md //iOS文档
└── Windows
```

## SDK 下载

| 所属平台 | Zip下载                                                      | Demo运行说明                                                 | SDK集成指引                                                  | API 列表                                                     |
| -------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| iOS      | [下载](https://mediacloud-76607.gzc.vod.tencent-cloud.com/TXCopyrightedMedia/Release/2.1.0/TXCopyrightedMedia-iOS-2.1.0.220303.zip) | [DOC](https://github.com/tencentyun/ame-ktv-sdk/blob/master/iOS/README.md) | [DOC](https://github.com/tencentyun/ame-ktv-sdk/blob/master/iOS/README.md) | [API](https://github.com/tencentyun/ame-ktv-sdk/blob/master/iOS/README.md) |
| Android  | [下载](https://mediacloud-76607.gzc.vod.tencent-cloud.com/TXCopyrightedMedia/Release/2.1.0/TXCopyrightedMedia-Android-trtc-2.1.0.220303.zip) | [DOC](https://github.com/tencentyun/ame-ktv-sdk/blob/master/Android/README.md) | [DOC](https://github.com/tencentyun/ame-ktv-sdk/blob/master/Android/README.md) | [API](https://github.com/tencentyun/ame-ktv-sdk/blob/master/Android/README.md) |
| Win(C++) | 暂无                                                         | [DOC](https://cloud.tencent.com/document/product/647/32397)  | [DOC](https://cloud.tencent.com/document/product/647/32178)  | [API](https://cloud.tencent.com/document/product/647/32268)  |

## Version 2.1.0 @ 2022.03.03

**新功能**

- Android：

  1、优化和解决已知问题

- iOS：

  1、优化和解决已知问题

  2、添加license下载完成回调

## Version 1.0.5 @ 2022.01.13

**新功能**

- Android：

  1、优化线程池

  2、优化合规问题

- iOS：

  1、修复iOS15切换后台播放上报crash信息

  2、加强切换到后台时候的播放能力

  3、 iPhone锁屏时license校验失败

## Version 1.0.4 @ 2021.10.22

**新功能**

- Android：升级所有接口，支持多码率选择。
- iOS：升级所有接口，支持多码率选择。

## Version 1.0.3 @ 2021.08.03

**问题修复**

- Android：修复读取本地缓存音乐和网络下载音乐线程池抢占问题
- iOS：修复部分歌曲不能播放问题
