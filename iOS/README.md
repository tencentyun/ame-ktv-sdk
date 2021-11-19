## 实时音视频TRTC & 正版版权曲库直通车AME在线KTV解决方案
## 一、产品概述
实时音视频TRTC & 版权曲库AME在线KTV联合解决方案深度整合腾讯在音视频深度积累的技术能力以及音乐内容版权上的核心优势产生1+1大于2的化学反应，帮助开发者极速搭建在线KTV业务。

实时音视频TRTC提供全球端到端平均延时<300 ms实时连麦以及10万人< 1s的超低延时观看的技术方案。
同时面向在线KTV场景提供48kHz采样率，128kbps立体声音频、低延时耳返让线上拥有媲美线下的KTV体验；更有变声、气氛音效、混响等多种趣味玩法。

正版曲库直通车(Authorized Music Express，AME)聚合TME等多家版权方优质曲目资源，结合腾讯云存储、编解码、内容分发、边缘计算等能力，有效解决多场景音乐素材应用版权问题。您可在控制台选购单曲/曲库包，提供下载/API/SDK多种接入方式，灵活高效实现正版音乐素材在多端的顺畅播放与应用。

## 二、产品原理

流程图：

```mermaid
sequenceDiagram
participant App客户端
participant App后台
participant TRTC SDK
participant TXCopyrightedMedia
participant 腾讯云后台

App客户端 ->> App后台:请求搜索音乐
App后台 ->> 腾讯云后台:请求搜索音乐 SearchKTVMusics
腾讯云后台 -->> App后台:返回音乐列表
App后台 -->> App客户端:返回音乐列表

App客户端 -->> App后台:请求音乐详情
App后台 ->> 腾讯云后台:请求音乐详情 DescribeKTVMusicDetail（带musicId）
腾讯云后台 -->> App后台:返回音乐详情
App后台 -->> App客户端:返回音乐详情

App客户端 ->> TXCopyrightedMedia:preloadMusic（传入musicId+playToken）
TXCopyrightedMedia ->> 腾讯云后台:请求Music数据
腾讯云后台 -->> TXCopyrightedMedia:返回Music数据
TXCopyrightedMedia -->> App客户端:回调preloadMusic进度和结果
App客户端 ->> TRTC SDK:startPlayMusic（传入genMusicURI返回值）
```
## 三、接入前准备工作

## 3.1 账号注册及认证
• 注册[腾讯云账号](https://cloud.tencent.com/register?s_url=https%3A%2F%2Fcloud.tencent.com%2F)。<br>
• 完成[实名认证](https://cloud.tencent.com/document/product/378/3629)。<br>

## 3.2 服务开通
• 正版曲库直通车AME 服务开通：登录[正版曲库直通车AME控制台](https://console.cloud.tencent.com/ame)后，您可在勾选同意[腾讯云服务协议](https://cloud.tencent.com/document/product/301/1967)以及[正版曲库直通车服务协议](https://cloud.tencent.com/document/product/1155/40757)后单击【立即开通】，即可开通服务。<br>
• 实时音视频TRTC 服务开通：登录[实时音视频TRTC控制台](https://console.cloud.tencent.com/trtc)开通并使用产品。<br>

<img width="" src="Doc/pic/884134D1616F4859B32DCC9E467F5888/image.png" alt="image.png" />

## 3.3 应用创建
您可在左导航栏进入【应用管理】页面，单击“创建应用”按钮，根据弹窗填空提示，填写相应的信息。
1. 应用名称：指接入APP应用名称。应用名称涉及版权授权，请准确填写，创建后无法再次修改。
2. Android PackageName：指接入应用在安卓应用市场的PackageName。请准确填写，创建后无法再次修改。
3. IOS BundleID：指接入应用在IOS应用市场的BundleID，请准确填写，创建后无法再次修改。
4. 应用场景：请根据接入应用的具体使用场景如实选择(语聊房/直播/FM)。
5. DAU：请基于接入应用实际情况准确填写。

<img width="" src="Doc/pic/95BFC41F8A944956A327C91BBE5C0F66/image.png" alt="image.png" />

## 3.4 白名单添加
因产品尚在内测，在正式接入之前，请联系对应商务经理为您添加白名单。

## 3.5 API联调

| API名称     | 描述   | 使用说明                   |
| ---------- | ------ | ---------------------- |
| SearchKTVMusics | 搜索KTV曲库 |  [文档地址](https://cloud.tencent.com/document/product/1155/56401) |
| DescribeKTVMusicDetail | 查询曲库歌曲详情 | [文档地址](https://cloud.tencent.com/document/product/1155/56402) |

a、首先调用 SearchKTVMusics 搜索目标歌曲，返回的列表包含歌曲的信息及Id

```java
// 请求
POST / HTTP/1.1
Host: ame.tencentcloudapi.com
Content-Type: application/json
X-TC-Action: SearchKTVMusics
<公共请求参数>

{
    "Limit": 10,
    "KeyWord": "周杰伦",
    "Offset": 0
}

// 响应
{
  "Response": {
    "TotalCount": 1,
    "KTVMusicInfoSet": [
      {
        "ComposerSet": [
          "方文山"
        ],
        "MusicId": "ame-78dxxx",
        "SingerSet": [
          "周杰伦"
        ],
        "Name": "七里香",
        "LyricistSet": [
          "周杰伦"
        ],
        "TagSet": [
          "华语",
          "流行"
        ]
      }
    ],
    "RequestId": "xx"
  }
}
```

b、根据上面接口返回的 Id 查询歌曲详情，包含 SDK 中所需要的 PlayToken

```java
// 请求
POST / HTTP/1.1
Host: ame.tencentcloudapi.com
Content-Type: application/json
X-TC-Action: DescribeKTVMusicDetail
<公共请求参数>

{
    "MusicId": "ame-78d2xxx"
}

// 响应
{
  "Response": {
    "PlayToken": "DUE3344xxxxxx",
    "KTVMusicBaseInfo": {
      "ComposerSet": [
        "周杰伦"
      ],
      "MusicId": "ame-78d2xxx",
      "SingerSet": [
        "周杰伦"
      ],
      "Name": "七里香",
      "LyricistSet": [
        "方文山"
      ],
      "TagSet": [
        "华语",
        "流行"
      ]
    },
    "RequestId": "xx"
  }
}
```


## 3.6 SDK接入
## 3.6.1 集成SDK
a、集成版权曲库SDK(拷贝TXCopyrightedMedia.framework)到项目工程中并集成

b、如果使用pod导入，则在podfile里面添加:
```
pod 'TXCopyrightedMedia'
```
c、[参考此处集成TRTC SDK](https://cloud.tencent.com/document/product/647/32173)

## 3.6.2 使用SDK

#### 获取TXCopyrightedMedia单例

**说明**

获取TXCopyrightedMedia单例

**接口**

```java
TXCopyrightedMedia *copyrightedMedia = [TXCopyrightedMedia instance];
```



#### 设置License

**说明**

设置license

**接口**

```java
[copyrightedMedia setLicense:licenseUrl key:key];
```

**参数说明**

| 参数名     | 类型   | 描述                   |
| ---------- | ------ | ---------------------- |
| licenseUrl | NSString | 控制台生成的licenseUrl |
| key        | NSString | 控制台生成的key        |



#### 初始化TXCopyrightedMedia

**说明**

初始化TXCopyrightedMedia。

**接口**

```java
[copyrightedMedia initialization];
```



#### 销毁TXCopyrightedMedia

**说明**

当程序退出后调用销毁。

**接口**

```java
[TXCopyrightedMedia destroy];
```



#### 预加载Music数据

**说明**

预加载Music数据，每次播放/重播前都需要调用该接口。

**接口**

```java
[copyrightedMedia preloadMusic:musicId bitrateDefinition:bitrateDefinition playToken:playToken callback:self]
```

**参数说明**

| 参数名    | 类型                  | 描述      |
| --------- | --------------------- | --------- |
| musicId | NSString              | 歌曲Id |
| bitrateDefinition | NSString | 码率描述（ audio/mi: 64 audio/lo: 128 audio/hi: 320） |
| playToken | NSString              | 播放Token |
| callback  | ITXMusicPreloadCallback | 回调代理 |


```java
@protocol ITXMusicPreloadCallback <NSObject>

@optional

- (void)onPreloadStart:(NSString *)musicId bitrateDefinition:(NSString *)bitrateDefinition;

- (void)onPreloadProgress:(NSString *)musicId
  			bitrateDefinition:(NSString *)bitrateDefinition
                 progress:(float)progress;

- (void)onPreloadComplete:(NSString *)musicId
  			bitrateDefinition:(NSString *)bitrateDefinition
                errorCode:(int)errorCode
                      msg:(NSString *)msg;

@end
```



#### 错误码

errorCode返回码定义如下

| 定义                          | 数值 | 描述              |
| ----------------------------- | ---- | ----------------- |
| TXCopyrightedErrorNoError     | 0    | 无错误            |
| TXCopyrightedErrorInitFail    | -1   | 初始化失败        |
| TXCopyrightedErrorCancel      | -2   | 用户取消数据获取  |
| TXCopyrightedErrorTokenFail   | -3   | token过期         |
| TXCopyrightedErrorNetFail     | -4   | 网络错误          |
| TXCopyrightedErrorInner       | -5   | 内部错误          |
| TXCopyrightedErrorParseFail   | -6   | 解析错误          |
| TXCopyrightedErrorDecryptFail | -7   | 解密错误          |
| TXCopyrightedErrorLicenseFail | -8   | License校验不通过 |



#### 取消预加载Music数据

**说明**

取消预加载Music数据。

**接口**

```java
[copyrightedMedia cancelPreloadMusic:musicId bitrateDefinition:bitrateDefinition];
```

**参数说明**

| 参数名    | 类型   | 描述      |
| --------- | ------ | --------- |
| musicId | NSString | 歌曲Id |
| bitrateDefinition | NSString | 码率描述（ audio/mi: 64 audio/lo: 128 audio/hi: 320） |



#### 检测是否已预加载Music数据

**说明**

检测是否已预加载Music数据。

**接口**

```java
BOOL isPreloaded = [copyrightedMedia isMusicPreloaded:musicId bitrateDefinition:bitrateDefinition];
```

**参数说明**

| 参数名            | 类型     | 描述                                                  |
| ----------------- | -------- | ----------------------------------------------------- |
| musicId           | NSString | 音乐Id                                                |
| bitrateDefinition | NSString | 码率描述（ audio/mi: 64 audio/lo: 128 audio/hi: 320） |



#### 生成Music URI

**说明**

生成Music URI，App客户端在preloadMusic成功之后调用，原唱&amp;伴奏传给TRTC进行播放。

**接口**

```java
NSString *musicUri = [copyrightedMedia genMusicURI:musicId bgmType:musicType bitrateDefinition:bitrateDefinition];
```

**参数说明**

| 参数名    | 类型   | 描述                       |
| --------- | ------ | -------------------------- |
| musicId | NSString | 歌曲Id                  |
| musicType   | Int    | 0：原唱，1：伴奏,  2：歌词 |
| bitrateDefinition | NSString | 码率描述（ audio/mi: 64 audio/lo: 128 audio/hi: 320） |

**返回说明**

| 返回值 | 类型   | 描述                                                         |
| ------ | ------ | ------------------------------------------------------------ |
| musicUri | NSString | 原唱&amp;伴奏：传给TRTC 播放的uri，格式 CopyRightMusic://audiotype=xxxx&musicid=xxxx&bitrate=xxxx；歌词：返回歌词的本地路径 |



#### 清理歌曲缓存

**说明**

清理本地所有缓存歌曲数据

**接口**

```java
[copyrightedMedia clearMusicCache];
```



#### 设置缓存歌曲最大数量

**说明**

设置缓存歌曲最大数量

**接口**

```java
[copyrightedMedia setMusicCacheMaxCount:maxCount];
```

**参数说明**

| 参数名   | 类型 | 描述                     |
| -------- | ---- | ------------------------ |
| maxCount | Int  | 歌曲最大缓存数量，默认50 |



## 3.6.3 代码示例

application 创建时候调用:
```java
[[TXCopyrightedMedia instance] setLicense:licence key:key];
```

进入主界面时候调用：

```java
[[TXCopyrightedMedia instance] initialization];
```


退出主界面时候调用：

```java
[TXCopyrightedMedia destroy];
```


进入K歌房间，点击K歌，下载Music：

```java
    TXCopyrightedMedia *copyRightedMedia = [TXCopyrightedMedia instance];
    if([copyRightedMedia isMusicPreloaded:musicId bitrateDefinition:@"audio/lo"]) {
         [self startPlayMusic];
    }else {
        [copyRightedMedia preloadMusic:musicId bitrateDefinition:@"audio/lo" playToken:playToken callback:self];
    }
}

- (void)startPlayMusic
{
    NSString *origintUri = [[TXCopyrightedMedia instance] genMusicURI:musicId bgmType:0 bitrateDefinition:@"audio/lo"];//获取原唱 uri
    NSString *accompUri = [[TXCopyrightedMedia instance] genMusicURI:musicId bgmType:1 bitrateDefinition:@"audio/lo"];//获取伴奏 uri
    // 注意，上面的 musicId 是曲库后台接口返回的字符串，用来区分存储在后台的音乐资源
    //      下面的 originMusicId 和 accompMusicId 是 int 型格式，您可以自己设置，
    //      用于 TRTC 的 BGM 播放接口区分不同的音乐使用，保证原唱和伴奏的 id 不同即可
    int originMusicId = 0;//原唱的 music id
    int accompMusicId = 1;//伴唱的 music id
    TXAudioMusicParam *originMusicParam = [[TXAudioMusicParam alloc] init];
    originMusicParam.ID = originMusicId;
    originMusicParam.path = origintUri;
    TXAudioMusicParam *accompMusicParam = [[TXAudioMusicParam alloc] init];
    accompMusicParam.ID = accompMusicId;
    accompMusicParam.path = accompUri;
    
    // 播放原唱和伴奏
    [[[TRTCCloud sharedInstance] getAudioEffectManager] startPlayMusic:originMusicParam onStart:^(NSInteger errCode) {

    } onProgress:^(NSInteger progressMS, NSInteger durationMS) {
        
    } onComplete:^(NSInteger errCode) {
        
    }];
    
    [[[TRTCCloud sharedInstance] getAudioEffectManager] startPlayMusic:accompMusicParam onStart:^(NSInteger errCode) {

    } onProgress:^(NSInteger progressMS, NSInteger durationMS) {
        
    } onComplete:^(NSInteger errCode) {
        
    }];
    
    //调用以下代码会播放并上行伴奏：
    [[[TRTCCloud sharedInstance] getAudioEffectManager] setMusicPlayoutVolume:originMusicId volume:0];
    [[[TRTCCloud sharedInstance] getAudioEffectManager] setMusicPlayoutVolume:accompMusicId volume:100];
    [[[TRTCCloud sharedInstance] getAudioEffectManager] setMusicPublishVolume:originMusicId volume:0];
    [[[TRTCCloud sharedInstance] getAudioEffectManager] setMusicPublishVolume:accompMusicId volume:100];
    
    //调用以下代码会播放并上行原唱：
    [[[TRTCCloud sharedInstance] getAudioEffectManager] setMusicPlayoutVolume:originMusicId volume:100];
    [[[TRTCCloud sharedInstance] getAudioEffectManager] setMusicPlayoutVolume:accompMusicId volume:0];
    [[[TRTCCloud sharedInstance] getAudioEffectManager] setMusicPublishVolume:originMusicId volume:100];
    [[[TRTCCloud sharedInstance] getAudioEffectManager] setMusicPublishVolume:accompMusicId volume:0];
}
```