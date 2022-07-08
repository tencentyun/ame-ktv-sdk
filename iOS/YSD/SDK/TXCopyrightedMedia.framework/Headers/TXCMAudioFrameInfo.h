//
//  TXCMAudioFrameInfo.h
//  TXCopyrightedMedia
//
//  Created by Zhirui Ou on 2021/12/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TXCMAudioFrameInfo : NSObject

@property (nonatomic, copy, readonly) NSString *frameId;
@property (nonatomic, assign) unsigned long long size;
@property (nonatomic, assign) long timestamp;

@end

NS_ASSUME_NONNULL_END
