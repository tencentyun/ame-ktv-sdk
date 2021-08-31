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
|	 ├─ Demo  //iOS ame的Demo
|  ├─ README.md //iOS文档
└── Windows
```

## SDK 下载

| 所属平台 | Zip下载                                                      | Demo运行说明                                                | SDK集成指引                                                 | API 列表                                                    |
| -------- | ------------------------------------------------------------ | ----------------------------------------------------------- | ----------------------------------------------------------- | ----------------------------------------------------------- |
| iOS      | [下载](https://liteav.sdk.qcloud.com/download/latest/TXLiteAVSDK_TRTC_iOS_latest.zip) | [DOC](https://cloud.tencent.com/document/product/647/32396) | [DOC](https://cloud.tencent.com/document/product/647/32173) | [API](https://cloud.tencent.com/document/product/647/32258) |
| Android  | [下载](https://liteav.sdk.qcloud.com/download/latest/TXLiteAVSDK_TRTC_Android_latest.zip) | [DOC](https://cloud.tencent.com/document/product/647/32166) | [DOC](https://cloud.tencent.com/document/product/647/32175) | [API](https://cloud.tencent.com/document/product/647/32267) |
| Win(C++) | [下载](https://liteav.sdk.qcloud.com/download/latest/TXLiteAVSDK_TRTC_Win_latest.zip) | [DOC](https://cloud.tencent.com/document/product/647/32397) | [DOC](https://cloud.tencent.com/document/product/647/32178) | [API](https://cloud.tencent.com/document/product/647/32268) |

## Version 1.0.3 @ 2021.08.03

**问题修复**

- Android：修复读取本地缓存音乐和网络下载音乐线程池抢占问题
- iOS：修复部分歌曲不能播放问题
