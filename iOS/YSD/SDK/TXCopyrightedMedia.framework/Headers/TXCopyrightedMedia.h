//
//  TXCopyrightedMedia.h
//  TXCopyrightedMedia
//
//  Created by Zhirui Ou on 2021/5/14.
//

#import <Foundation/Foundation.h>
#import "ITXMusicPreloadCallback.h"
#import "ITXMusicDownloadLicenseCallback.h"
#import "ITXCSongScore.h"
#import "TXCSongScoreConfig.h"
#import "ITXCMMusicTrack.h"
#import "TXCMusicInfo.h"
#import "TXCMMusicExtParams.h"

typedef NS_ENUM(NSInteger, TXCopyrightedError) {
    TXCopyrightedErrorNoError = 0,
    TXCopyrightedErrorInitFail = -1, //初始化失败
    TXCopyrightedErrorCancel = -2, // 用户取消数据获取
    TXCopyrightedErrorTokenFail = -3, // token过期
    TXCopyrightedErrorNetFail = -4, // 网络错误
    TXCopyrightedErrorInner = -5, // 内部错误
    TXCopyrightedErrorParseFail = -6, // 解析错误
    TXCopyrightedErrorDecryptFail = -7, // 解密错误
    TXCopyrightedErrorLicenseFail = -8, //License校验不通过
    TXCopyrightedErrorChorusNotFound = -10 // 高潮片段(副歌)缺失
};

typedef NS_ENUM(NSInteger, TXCMusicType) {
    TXCMusicTypeOrignal = 0,    // 原唱
    TXCMusicTypeAccompaniment,  // 伴奏
    TXCMusicTypeLyrics,         // 歌词
    TXCMusicTypeMidi            // Midi音高线
};

static NSString *EXT_INFO_ROOM_ID = @"RoomId"; // 房间id
static NSString *EXT_INFO_PLAY_SCENE = @"PlayScene"; // 播放场景
static NSString *PLAY_SCENE_CHAT = @"Chat"; // 语聊场景
static NSString *PLAY_SCENE_LIVE = @"Live"; // 直播场景

@interface TXCopyrightedMedia : NSObject

/// 获取TXCopyrightedMedia单例
+ (instancetype)instance;

/// 当程序退出后调用销毁。
+ (void)destroy;

/// 是否输出控制台日志
+ (void)enableLog:(BOOL)enable;

/// 获取sdk版本号
+ (NSString *)getSDKVersion;

/// 设置License
/// @param licenceUrl 控制台生成的licenceUrl
/// @param key 控制台生成的key
- (void)setLicense:(NSString *)licenceUrl
               key:(NSString *)key;


/// 设置License
/// @param licenceUrl 控制台生成的licenceUr
/// @param key 控制台生成的key
/// @param callback 监听回调，注意，多次setLicense只有最后一次会收到回调
- (void)setLicense:(NSString *)licenceUrl
               key:(NSString *)key
          callback:(id<ITXMusicDownloadLicenseCallback>)callback;

/// 开启服务，该函数为同步，必须在主线程调用
- (void)initialization;

/// 预加载音乐数据。
/// @param musicId 歌曲Id
/// @param playToken 播放Token
/// @param extParams 拓展字段,原有定义不变，比如：audio/default意义不变，表示的是 "音频/默认码率(整曲)"。 对应高潮片段定义为audio/default/chorus。
/// @param callback 回调结束后响应对象
- (void)preloadMusic:(NSString *)musicId
           extParams:(NSString *)extParams
           playToken:(NSString *)playToken
            callback:(id<ITXMusicPreloadCallback>)callback;

/// 取消预加载音乐数据。
/// @param musicId 歌曲Id
/// @param extParams 拓展字段,原有定义不变，比如：audio/default意义不变，表示的是 "音频/默认码率(/整曲)"。 对应高潮片段定义为audio/default/chorus。
- (void)cancelPreloadMusic:(NSString *)musicId extParams:(NSString *)extParams;


/// 检测是否已预加载音乐数据。
/// @param musicId 歌曲Id
/// @param extParams 拓展字段,原有定义不变，比如：audio/default意义不变，表示的是 "音频/默认码率(/整曲)"。 对应高潮片段定义为audio/default/chorus
- (BOOL)isMusicPreloaded:(NSString *)musicId extParams:(NSString *)extParams;

/// 生成音乐 URI，App客户端，播放时候调用，传给trtc进行播放。与preloadMusic一一对应
/// @param musicId 歌曲Id
/// @param bgmType 0：原唱，1：伴奏  2:  歌词
/// @param extParams 码率，传nil为改音频默认码率
- (NSString *)genMusicURI:(NSString *)musicId
                  bgmType:(TXCMusicType)bgmType
        extParams:(NSString *)extParams;

/// 清理所有音乐缓存
- (void)clearMusicCache;

/// 清理对应musicId和biteate的音乐缓存
- (void)clearMusicCache:(NSString *)musicId extParams:(NSString *)extParams;

/// 设置最大歌曲缓存数目，默认100
/// @param maxCount 歌曲最大数目
- (void)setMusicCacheMaxCount:(int)maxCount;

/// 创建音乐轨道类
- (id<ITXCMMusicTrack>)createMusicTrack:(TXCMusicInfo *)musicInfo;

/// 创建打分类
- (id<ITXCSongScore>)createSongScore:(TXCSongScoreConfig *)config;


/// 设置上报扩展字段，如：设置直播房间ID，只有在直播场景下，需要传值，计费方式不一样。
/// @param extName 扩展字段名：如EXT_INFO_ROOM_ID
/// @param extValue 扩展字段值
- (void)setExtInfoName:(NSString *)extName extValue:(NSString *)extValue;

@end

