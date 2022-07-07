//
//  IAgoraRtcEngine.h
//  TXCopyrightedMedia
//
//  Created by Zhirui Ou on 2021/12/20.
//

#import <Foundation/Foundation.h>

@class TXCMAudioFrameInfo;

NS_ASSUME_NONNULL_BEGIN

@protocol IAgoraRtcEngine <NSObject>

/// 功能与pushExternalAudioFrameRawData, 请参照AgoraRtcEngineKit头文件
/// @param info readAudioFrame得到的帧数据
/// @param sourcePos 参数与pushExternalAudioFrameRawData一致，请参照AgoraRtcEngineKit头文件
/// @param samplesPerChannel 参数与AgoraAudioFrame一致，请参照AgoraObjects头文件
/// @param bytesPerSample 参数与AgoraAudioFrame一致，请参照AgoraObjects头文件
/// @param channels 参数与AgoraAudioFrame一致，请参照AgoraObjects头文件
/// @param samplesPerSec 参数与AgoraAudioFrame一致，请参照AgoraObjects头文件
/// @param renderTimeMs 参数与AgoraAudioFrame一致，请参照AgoraObjects头文件
/// @param avSyncType 参数与AgoraAudioFrame一致，请参照AgoraObjects头文件
- (int)pushExternalAudioFrameRawData:(TXCMAudioFrameInfo *)info
                           sourcePos:(int)sourcePos
                   samplesPerChannel:(NSInteger)samplesPerChannel
                      bytesPerSample:(NSInteger)bytesPerSample
                            channels:(NSInteger)channels
                       samplesPerSec:(NSInteger)samplesPerSec
                        renderTimeMs:(int64_t)renderTimeMs
                          avSyncType:(NSInteger)avSyncType;

@end

NS_ASSUME_NONNULL_END
