//
//  ITXCSongScore.h
//  TXCopyrightedMedia
//
//  Created by Zhirui Ou on 2022/1/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ITXCSongScore;

@protocol TXCSongScoreDelegate <NSObject>

@optional

/// 每句歌词结束时的分数回调
/// @param songScore 当前回调的打分类
/// @param currentScore 最新单句分数。范围[-1,100]整数。-1表示此句歌词没有对应曲调（例如：旁白）
/// @param totalScore 当前总分
/// @param curIndex 最新单句下标
- (void)songScoreDidUpdate:(id<ITXCSongScore>)songScore
              currentScore:(int)currentScore
                totalScore:(int)totalScore
                  curIndex:(int)curIndex;

/// 总分回调
/// @param songScore 当前回调的打分类
/// @param scoreArray 单句得分数组
/// @param totalScore 总得分
- (void)songScoreDidFinish:(id<ITXCSongScore>)songScore
                scoreArray:(NSArray *)scoreArray
                totalScore:(int)totalScore;

/// 实时命中音准回调
/// @param songScore 当前回调的打分类
/// @param timeStamp 间隔时间戳，上一次回调给出去的时间的结束就是这次回调出去时间的起始。
/// @param isHit 是否命中
/// @param pitch 用户音高（数值可与note音高对比, -1表示没有音高)
/// @param viewValue UI展示的音高
- (void)songScoreDidGroveAndHit:(id<ITXCSongScore>)songScore
                      timeStamp:(double)timeStamp
                          isHit:(BOOL)isHit
                          pitch:(float)pitch
                      viewValue:(int)viewValue;

/// 开始准备成功，开始打分
/// @param songScore 当前回调的打分类
- (void)songScoreOnPrepared:(id<ITXCSongScore>)songScore;

/// 错误回调
/// @param songScore 当前回调的打分类
/// @param errCode 错误码
/// @param msg 错误信息
- (void)songScoreOnError:(id<ITXCSongScore>)songScore
                 errCode:(int)errCode
                     msg:(NSString *)msg;

@end

@protocol ITXCSongScore <NSObject>

/// 打分类回调代理
@property (nonatomic, weak) id<TXCSongScoreDelegate> delegate;

/// 初始化准备
- (void)prepare;

/// 销毁
- (void)destory;

/// 流数据输入
/// @param buffer PCM缓冲
/// @param length 字节长度
/// @param timeStamp 伴奏时间（单位：毫秒）
- (void)process:(char *)buffer length:(int)length timeStamp:(double)timeStamp;

/// seek
/// @param timeStamp 时间戳（单位：毫秒）
- (void)seek:(double)timeStamp;

/// 计算完分数后从callback里返回
- (void)finish;

/// 升降调
/// @param shiftValue 升降调的值
/// 通常用于升降音调唱歌，比如用户要提高一个半音唱歌，此时shiftValue = 1。
/// 最高12个半音，最低12个半音。（12个半音=1个八度）
- (void)setKeyShift:(NSInteger)shiftValue;

/// noteUI 给UI展示使用
/// NSDictionary key 说明：
/// key NSString类: begin，value NSNumber类 起始时间(单位:ms)
/// key NSString类: end，value  NSNumber类 结束时间(单位:ms)
/// key NSString类: noteHeight，value NSNumber类 UI展示使用音高
- (NSArray <NSDictionary *> *)getAllGrove;

/// 返回歌曲满分总分
/// @return 满分值
- (int)calculateTotalScore;

@end

NS_ASSUME_NONNULL_END
