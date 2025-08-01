//
//  KRWaterMeterKit.h
//  KRoadWaterMeter
//
//  Created by 远征 马 on 2017/5/5.
//  Copyright © 2017年 马远征. All rights reserved.
/**
 1.2.0更新
 1.开启日志打印 startLog
 2.增加 connectionSuccessfulHandler连接成功、connectionFailHandler连接失败、disconnectHandler断开连接 blcok回调
 3.修改- (void)scanForPeripherals:(NSString *)uuidString retHandler:(KRWMPeriphralsHandler)handler; 指定uuidString为自动连接
 4.修改- (void)scanForPeripheralsWithMacAddress:(NSString *)macAddress retHandler:(KRWMPeriphralsHandler)handler; 指定macAddress为自动连接
 5.增加- (void)krColdWaterMeterGetStateOfDevice:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler; 获取冷水表设备信息
 6.增加- (void)krPublicSendData:(NSData *)data funCode:(unsigned int)funCode dataCallback:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler; 公用设备发送数据
 7.增加+ (NSString *)getVersionString 获取SDK版本号
 */

#ifndef KRWaterMeterKit_h
#define KRWaterMeterKit_h

#import "KRWMCore.h"
#import "KRWMUtils.h"
#import "KRWMConstants.h"
#import "KRWMObject.h"
#import "KRWMSetHeatPumpObject.h"
#endif /* KRWaterMeterKit_h */
