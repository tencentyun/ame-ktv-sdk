//
//  ITXMusicPreloadCallback.h
//  TXCopyrightedMedia
//
//  Created by Zhirui Ou on 2021/5/17.
//

#import <Foundation/Foundation.h>

@protocol ITXMusicPreloadCallback <NSObject>

@optional

//开始下载回调
- (void)onPreloadStart:(NSString *)musicId extParams:(NSString *)extParams;

//下载进度回调
- (void)onPreloadProgress:(NSString *)musicId
        extParams:(NSString *)extParams
                 progress:(float)progress;

//下载完成回调
- (void)onPreloadComplete:(NSString *)musicId
        extParams:(NSString *)extParams
                errorCode:(int)errorCode
                      msg:(NSString *)msg;

@end
