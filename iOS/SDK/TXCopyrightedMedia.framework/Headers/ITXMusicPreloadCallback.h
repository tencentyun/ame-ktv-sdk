//
//  ITXMusicPreloadCallback.h
//  TXCopyrightedMedia
//
//  Created by Zhirui Ou on 2021/5/17.
//

#import <Foundation/Foundation.h>

@protocol ITXMusicPreloadCallback <NSObject>

@optional

- (void)onPreloadStart:(NSString *)musicId;

- (void)onPreloadProgress:(NSString *)musicId
                 progress:(float)progress;

- (void)onPreloadComplete:(NSString *)musicId
                errorCode:(int)errorCode
                      msg:(NSString *)msg;

@end
