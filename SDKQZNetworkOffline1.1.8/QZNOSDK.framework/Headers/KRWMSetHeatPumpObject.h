//
//  KRWMSetHeatPumpObject.h
//  WisdomCampusSDK
//
//  Created by 李志权 on 2020/6/15.
//  Copyright © 2020 李志权. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KRUpDataMQTT : NSObject

/// 0：俩个都更新  1：只更新MqttAddr 2.只更新topic后缀
@property (nonatomic,strong) NSNumber *state;

/// MqttAddr的长度
@property (nonatomic,strong) NSNumber *addrLen;
/// ASCII转HEX，后边补0.
@property (nonatomic,strong) NSString *mqttAddr;
/// 只改topic后缀 预留目前默认1
@property (nonatomic,strong) NSNumber *topic_n;
/// 端口号
@property (nonatomic,strong) NSNumber *portNum;
- (NSData*)writeData;
@end

#pragma mark 设置水表
@interface KRSetWaterMeter : NSObject

/// 项目编号
@property (nonatomic,strong) NSNumber *projectId;

/// 1路水表内置地址 如：输入70809408  需前面补0补齐为14位
@property (nonatomic,strong) NSString *waterDevaddr1;
/// 预留水表 同理1路水表
@property (nonatomic,strong) NSString *waterDevaddr2;
/// 水表波特率设置 (默认2400：十六进制：09 60)
@property (nonatomic,strong) NSNumber *waterBaud;
/// 水表协议版本 V1-V10 对应发00-09
@property (nonatomic,strong) NSNumber *waterVersion;
- (NSData*)writeData;
@end
#pragma mark 设置电表
@interface KRSetElectricMeter : NSObject
/// 项目编号
@property (nonatomic,strong) NSNumber *projectId;
/// 1路电表内置地址 如：输入180907374 需前面补0补齐12位
@property (nonatomic,strong) NSString *electricDevaddr1;
/// 2路电表内置地址（预留）同理2路电表
@property (nonatomic,strong) NSString *electricDevaddr2;
/// 水表波特率设置 (默认2400：十六进制：09 60)
@property (nonatomic,strong) NSNumber *electricBaud;
/// 水表协议版本 V1-V10 对应发00-09
@property (nonatomic,strong) NSNumber *electricVersion;
- (NSData*)writeData;
@end

#pragma mark 获取热泵设备信息
@interface KRGetHeatPumpInfo : NSObject

/// 12位MAC地址 MAC:0015830149A2
@property (nonatomic,copy,readonly) NSString *macAddress;
/// 项目编号
@property (nonatomic,copy,readonly) NSNumber *projectId;

/// 软件版本号
@property (nonatomic,copy,readonly) NSString *verSoft;
/// 水表地址
@property (nonatomic,copy,readonly) NSString *waterDevaddr;
/// 电表地址
@property (nonatomic,copy,readonly) NSString *electricDevaddr;
/// 主题只改后缀
@property (nonatomic,copy,readonly) NSNumber *topic_n;
/// SIM卡号
@property (nonatomic,copy,readonly) NSString *CCID;
/// MqttAddr长度
@property (nonatomic,copy,readonly) NSNumber *addrLen;
/// MqttAddr地址
@property (nonatomic,copy,readonly) NSString *mqttAddr;
/// 端口号
@property (nonatomic,copy,readonly) NSNumber *portNum;
/// 水表波特率设置
@property (nonatomic,copy,readonly) NSNumber *waterBaud;
/// 电表波特率设置
@property (nonatomic,copy,readonly) NSNumber *electricBaud;
/// 水表协议版本
@property (nonatomic,copy,readonly) NSNumber *waterVersion;
/// 电表协议版本
@property (nonatomic,copy,readonly) NSNumber *electricVersion;


/**
 @discussion 解析热泵设备信息
 @param data 设备数据
 @return <code>KRGetHeatPumpInfo</code>对象，如果data为<i>nil</i>,返回空
 */
+ (instancetype)heatPumpInfoDetailsObjectWithDetailsFromData:(NSData *)data;
@end

