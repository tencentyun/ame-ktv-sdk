//
//  TXCopyrightedMedia.h
//  TXCopyrightedMedia
//
//  Created by Zhirui Ou on 2021/5/14.
//

#import <Foundation/Foundation.h>
#import "ITXMusicPreloadCallback.h"

typedef NS_ENUM(NSInteger, TXCopyrightedError) {
    TXCopyrightedErrorNoError = 0,
    TXCopyrightedErrorInitFail = -1, //初始化失败
    TXCopyrightedErrorCancel = -2, // 用户取消数据获取
    TXCopyrightedErrorTokenFail = -3, // token过期
    TXCopyrightedErrorNetFail = -4, // 网络错误
    TXCopyrightedErrorInner = -5, // 内部错误
    TXCopyrightedErrorParseFail = -6, // 解析错误
    TXCopyrightedErrorDecryptFail = -7, // 解密错误
    TXCopyrightedErrorLicenseFail = -8 //License校验不通过
};

@interface TXCopyrightedMedia : NSObject

/// 获取TXCopyrightedMedia单例
+ (instancetype)instance;

/// 当程序退出后调用销毁。
+ (void)destroy;

/// 是否输出控制台日志
+ (void)enableLog:(BOOL)enable;

/// 设置License
/// @param licenceUrl 控制台生成的licenceUrl
/// @param key 控制台生成的key
- (void)setLicense:(NSString *)licenceUrl
               key:(NSString *)key;

/// 开启
- (void)initialization;

/// 预加载音乐数据。
/// @param musicId 歌曲Id
/// @param playToken 播放Token
/// @param bitrateDefinition 码率，传nil为改音频默认码率
/// @param callback 回调结束后响应对象
- (void)preloadMusic:(NSString *)musicId
   bitrateDefinition:(NSString *)bitrateDefinition
           playToken:(NSString *)playToken
            callback:(id<ITXMusicPreloadCallback>)callback;

/// 取消预加载音乐数据。
/// @param musicId 歌曲Id
/// @param bitrateDefinition 码率，传nil为改音频默认码率
- (void)cancelPreloadMusic:(NSString *)musicId bitrateDefinition:(NSString *)bitrateDefinition;


/// 检测是否已预加载音乐数据。
/// @param musicId 歌曲Id
/// @param bitrateDefinition 码率，传nil为改音频默认码率
- (BOOL)isMusicPreloaded:(NSString *)musicId bitrateDefinition:(NSString *)bitrateDefinition;

/// 生成音乐 URI，App客户端，播放时候调用，传给trtc进行播放。与preloadMusic一一对应
/// @param musicId 歌曲Id
/// @param bgmType 0：原唱，1：伴奏  2:  歌词
/// @param bitrateDefinition 码率，传nil为改音频默认码率
- (NSString *)genMusicURI:(NSString *)musicId
                  bgmType:(int)bgmType
        bitrateDefinition:(NSString *)bitrateDefinition;

/// 清理音乐缓存
- (void)clearMusicCache;

/// 设置最大歌曲缓存数目，默认100
/// @param maxCount 歌曲最大数目
- (void)setMusicCacheMaxCount:(int)maxCount;

@end

