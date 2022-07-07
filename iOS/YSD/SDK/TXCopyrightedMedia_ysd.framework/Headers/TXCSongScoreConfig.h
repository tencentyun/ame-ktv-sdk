//
//  TXCSongScoreConfig.h
//  TXCopyrightedMedia
//
//  Created by Zhirui Ou on 2022/1/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 打分模块初始化配置项
@interface TXCSongScoreConfig : NSObject

/// 采样率
@property (nonatomic, assign) int sampleRate;

/// 声道
@property (nonatomic, assign) int channel;

/// 音准文件路径
@property (nonatomic, copy) NSString *noteFilePath;

/// 歌词路径
@property (nonatomic, copy) NSString *lyricFilePath;

@end

NS_ASSUME_NONNULL_END
