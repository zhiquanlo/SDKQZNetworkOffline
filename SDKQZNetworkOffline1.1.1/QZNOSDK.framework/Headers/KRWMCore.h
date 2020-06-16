//
//  KRWMCore.h
//  KRoadWaterMeter
//
//  Created by 远征 马 on 2017/5/5.
//  Copyright © 2017年 马远征. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "KRWMBlock.h"
#import "KRWMDefine.h"


/**
 蓝牙通讯核心文件
 */
@interface KRWMCore : NSObject
@property (nonatomic, strong, readonly) CBPeripheral  *peripheral;
/**
 蓝牙同步类型
 */
@property (nonatomic, assign, readonly) KRSyncType syncType;

/**
 蓝牙同步状态
 */
@property (nonatomic, assign, readonly, getter=isSynchronizing) BOOL synchronizing;

/**
 centralManager状态，通过通知或者kvo可以观察蓝牙状态变化
 */
@property (nonatomic, assign)  KRManagerState managerState;


/**
 扫描过滤设备名字，通过此参数可以过滤掉不符合要求的蓝牙外设。 如需要扫描 HX4-055 的蓝牙，配置 @"hx4"类似前缀，或者@“x4-055“则可以实现扫描，如果传入nil，则扫描所有外设
 */
@property (nonatomic, strong) NSString *scanFilterName;

/**
 蓝牙最大扫描距离，如果不设置则扫描所有范围的蓝牙
 */
@property (nonatomic, strong) NSNumber *maxScanDistance;


/**
 设置蓝牙指令响应超时时间
 */
@property (nonatomic, assign) NSTimeInterval timeOutInterval;

// 日志显示
@property (nonatomic, assign) BOOL logStringChanged;
@property (nonatomic, strong) NSMutableString *AllLogString;



+ (instancetype)sharedCore;


/**
 扫描蓝牙外设，如果uuidString存在则返回指定uuidString的外设，不存在则扫描所有符合条件的外设

 @param uuidString 蓝牙uuid字符串
 @param handler 扫描结果回调block
 */
- (void)scanForPeripherals:(NSString *)uuidString retHandler:(KRWMPeriphralsHandler)handler;


/**
 扫描蓝牙外设，如果macAddress不存在则扫描所有外设，否则扫描指定mac地址的外设

 @param macAddress 蓝牙mac地址
 @param handler 扫描结果回调
 */
- (void)scanForPeripheralsWithMacAddress:(NSString *)macAddress retHandler:(KRWMPeriphralsHandler)handler;

/**
 停止扫描外设
 */
- (void)stopScan;

/**
 判断当前<i>peripheral</i>是否正在连接

 @return YES/NO
 */
- (BOOL)isConnecting;

/**
 判断当前<i>peripheral</i>是否已经连接

 @return YES/NO
 */
- (BOOL)isConnected;

/**
 连接<i>peripheral</i>
 
 @param peripheral 蓝牙外设对象
 @return YES/NO,如果<i>peripheral</i>存在，返回YES，否则返回NO
 */
- (BOOL)connectPeripheral:(CBPeripheral*)peripheral;


/**
 断开当前外设的连接
 */
- (void)disconnect;



/**
 断开<i>peripheral</i>连接

 @param peripheral 蓝牙外设
 @return YES/NO,如果<i>peripheral</i>存在，返回YES，否则返回NO
 */
- (BOOL)disconnectPeripheral:(CBPeripheral*)peripheral;


#pragma mark - 蓝牙通讯
/**
 设置和读取设备类型
 @param type 00读取 01为写入
 @param MAXType 1 设备主类型(0:水表，1:饮水机，2:洗衣机，3:吹风机，4 充电 器)
 @param MINType 设备子类型 (0-9 子类)
 @param dataCallback 响应结果回调
 @param retHandler 同步结果回调
 */
- (void)krReadingDeviceDataType:(NSNumber *)type MAXType:(NSNumber *)MAXType MINType:(NSNumber *)MINType dataCallback:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler;

/**
 清除设备项目信息
 
 @param dataCallback 响应结果回调
 @param retHandler 同步结果回调
 */
- (void)krClearNumOfDevice:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler;


/**
 @discussion 下发项目编号，操作员用

 @param deviceId 设备id
 @param productId 产品id
 @param dataCallback 响应数据回调
 @param retHandler 同步结果回调
 */
- (void)krAssignNumForDevice:(NSNumber*)deviceId productId:(NSNumber*)productId dataCallback:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler;
/**
 @discussion 设置密钥1_1协议
 @param keyData 密钥数据
 @param dataCallback 响应数据回调
 @param retHandler 同步结果回调
 */
- (void)krV1_1SetKeyData:(NSData*)keyData dataCallback:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler;

/**
 @discussion 分配费率参数(包含V1_1协议)

 @param data 费率参数信息
 @param commMode 通信版本
 @see KRRateObject
 @param dataCallback 响应数据回调
 @param retHandler 同步结果回调
 */
- (void)krAssginRateForDevice:(NSData*)data commMode:(NSString *)commMode  dataCallback:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler;


/**
 @discussion 结束消费指令，此指令发出成功后水表停止放水
 @param dataCallback 响应数据回调
 @param retHandler 同步结果回调
 */
- (void)KrStopUsingWater:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler;


/**
 @discussion 获取设备状态，设备状态空闲的时候可以下发费率启动水表放水，其他状态需要采集消费数据后清除消费信息

 @param dataCallback 响应数据回调
 @param retHandler 同步结果回调
 */
- (void)krGetStateOfDevice:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler;


/**
 @discussion 采集消费数据
 @see KRConsumptionDetailsObject
 @param dataCallback 响应数据回调
 @param retHandler 同步结果回调
 */
- (void)krGetConsumptionDetails:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler;


/**
 @discussion 清除消费数据

 @param data 记录查询相关数据，此数据有采集消费数据获取到的<i>KRConsumptionDetailsObject</i>对象生成
 @see KRConsumptionDetailsObject
 @param dataCallback 响应数据回调
 @param retHandler 同步结果回调
 */
- (void)krClearConsumptionDetails:(NSData*)data dataCallback:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler;
/**
 @discussion 开始交易（包含1.1协议）
 @param data 交易信息
 @see KRTransactionObject
 @param dataCallback 响应数据回调
 @param retHandler 同步结果回调
 */
- (void)krTransactionRateForDetails:(NSData*)data dataCallback:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler;


/**
 @discussion 交易结束(订单模式)
 @param MAXType 1 设备主类型(0:水表，1:饮水机，2:洗衣机，3:吹风机，4 充电 器)
 @param MINType 设备子类型 (0-9 子类)
 @see KRTransactionObject
 @param dataCallback 响应数据回调
 @param retHandler 同步结果回调
 */
- (void)krEndTransactionMAXType:(NSNumber *)MAXType MINType:(NSNumber *)MINType dataCallback:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler;

/**
 @discussion 交易结束(订单模式V1_1版本)
 @see KRTransactionObject
 @param dataCallback 响应数据回调
 @param retHandler 同步结果回调
 */
- (void)krV1_1EndTransactionDataCallback:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler;
/**
 @discussion 交易结束(水控设备V1_1版本)
 @see KRTransactionObject
 @param dataCallback 响应数据回调
 @param retHandler 同步结果回调
 */
- (void)krV1_1EndWaterTransactionDataCallback:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler;
/**
 @discussion 交易开始(电控设备)(水控设备V1_1版本)
 @param data 交易信息
 @param dataCallback 响应数据回调
 @param retHandler 同步结果回调
 */
- (void)krV1_1ElectricTransactionRateForDetails:(NSData*)data dataCallback:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler;

@end
