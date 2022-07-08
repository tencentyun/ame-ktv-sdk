//
//  ITXMusicSetLicenseCallback.h
//  TXCopyrightedMedia
//
//  Created by Zhirui Ou on 2022/3/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ITXMusicDownloadLicenseCallback <NSObject>

/// setLicense完成时回调
/// @param errorCode 内部错误码，0表示没有错误
/// @param msg 错误信息
- (void)onDownloadLicenseComplete:(int)errorCode
                              msg:(NSString *)msg;

@end

NS_ASSUME_NONNULL_END
