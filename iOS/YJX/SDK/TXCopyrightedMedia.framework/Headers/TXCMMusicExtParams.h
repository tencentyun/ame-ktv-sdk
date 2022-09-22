//
//  TXCMMusicExtParams.h
//  TXCopyrightedMedia
//
//  Created by chavezchen on 2022/9/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, TXCMusicClipType) {
    TXCMusicClipTypeFull = 0,    // 整曲
    TXCMusicClipTypeChorus  // 高潮片段(副歌)
};

@interface TXCMMusicExtParams : NSObject
// 音乐码率 现在ysd默认只有一种：audio/default。 yjx: audio/lo audio/mi audio/hi
@property (nonatomic, copy) NSString *bitrateDefinition;
// 片段类型。目前暂不支持高潮片段
@property (nonatomic, assign) TXCMusicClipType clipType;

// 根据对象设置的码率和类型 获取对应的ExtParams。可传递给TXCopyrightedMedia的相关接口使用
- (NSString *)getMusicExtParams;

// 根据扩展字段字符串，获取TXCMMusicExtParams对象
+ (instancetype)extParamsObjWithExtparams:(NSString *)extParams;

@end

NS_ASSUME_NONNULL_END
