//
//  TXCMusicInfo.h
//  AudioStream
//
//  Created by Zhirui Ou on 2021/12/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TXCMusicInfo : NSObject

@property (nonatomic, copy) NSString *musicId;
@property (nonatomic, assign) int musicType; // 0:原唱  1:伴奏
@property (nonatomic, copy) NSString *extParams;

@end

NS_ASSUME_NONNULL_END
