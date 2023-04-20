//
//  ITXCMMusicTrack.h
//  AudioStream
//
//  Created by Zhirui Ou on 2021/12/2.
//

#import <Foundation/Foundation.h>

@class TXCMusicInfo;
@class TXCMAudioFrameInfo;
@protocol ITXCMMusicTrack;

NS_ASSUME_NONNULL_BEGIN

@protocol TXCMMusicTrackDelegate <NSObject>

@optional

- (void)onPrepared:(id<ITXCMMusicTrack>)musicTrack;

- (void)onError:(id<ITXCMMusicTrack>)musicTrack errCode:(int)errCode msg:(NSString *)msg;

@end

@protocol ITXCMMusicTrack <NSObject>

/// onPrepared后调用，返回采样率，16000、24000、32000、44100、48000等
- (int)getSampleRate;

/// onPrepared后调用，返回声道数
- (int)getChannelCount;

/// onPrepared后调用,获取每个通道的位深
- (int)getBitsPerChannel;

/// onPrepared后调用,获取每帧采样点数
- (int)getFramePerPacket;

/// onPrepared后调用，返回音轨时长。单位:millisecond
- (int)getDuration;

/// 获取最近一次解码得到的帧时间戳。单位:millisecond
- (long)getPresentTimeMs;

/// 设置代理回调
/// @param delegate 代理
- (void)setDelegate:(id<TXCMMusicTrackDelegate>)delegate;

/// 准备音频数据，异步回调onPrepared
- (void)prepare;

/// 准备音频数据，同步耗时接口
- (void)prepareSync;

/// onPrepared后调用，开始音频解码
- (void)start;

/// 跳转音乐的解码进度，注意：请尽量避免过度频繁地调用该接口，因为该接口可能会再次读写音乐文件，耗时稍高。
/// @param pts seek时间，单位：ms,  接口会修正传入的pts的值，得到附近精确的pts
- (void)seek:(int *)pts;

/// 读帧， 读取到的大小，-1代表文件末尾
- (int)read:(void *)audioData;

/// 读帧， 如果为nil，则为读到末尾
- (TXCMAudioFrameInfo *)readAudioFrame;

/// 返回最小buffer大小
- (int)getMinBufferSize;

/// 停止音频轨道
- (void)stop;

/// 释放资源
- (void)destory;

/// 获取代理
- (id)getProxy:(id)engine;

@end

NS_ASSUME_NONNULL_END
