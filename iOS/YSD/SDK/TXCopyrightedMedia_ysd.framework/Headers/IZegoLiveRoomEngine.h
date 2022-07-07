//
//  IZegoLiveRoomEngine.h
//  TXCopyrightedMedia
//
//  Created by Zhirui Ou on 2021/12/29.
//

#import <Foundation/Foundation.h>

@class TXCMAudioFrameInfo;
@protocol IZegoLiveRoomEngine;


NS_ASSUME_NONNULL_BEGIN

@protocol TXCMZegoLiveRoomDelegate <NSObject>

@optional

- (TXCMAudioFrameInfo *)onLiveRoomAuxCallback:(id<IZegoLiveRoomEngine>)zegoProxy;

@end

@protocol IZegoLiveRoomEngine <NSObject>

- (void)setZegoLiveRoomDelegate:(id<TXCMZegoLiveRoomDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
