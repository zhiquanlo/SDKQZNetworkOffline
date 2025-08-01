//
//  KRWMObject.h
//  KRoadWaterMeter
//
//  Created by 远征 马 on 2017/5/5.
//  Copyright © 2017年 马远征. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@interface CBPeripheral (advertisementData)
@property (nonatomic,strong)  NSDictionary *advertisementData;
- (NSString*)macAddress;
- (NSString*)formattedMacAddress;
- (BOOL)isConnectEnable;
- (BOOL)isEqualToPeripheral:(id)object;
@end



#pragma mark - KRStateObject

/**
 @class KRStateObject
 @discussion 设备状态信息
 */
@interface KRStateObject : NSObject

/**
 @discussion 项目编号
 @property productId
 */
@property (nonatomic,copy,readonly)  NSNumber *productId;

/**
 @discussion 设备ID
 @property deviceId
 */
@property (nonatomic,copy,readonly)  NSNumber *deviceId;

/**
 @discussion 帐号(1)
 @property accountId
 */
@property (nonatomic,copy,readonly)  NSNumber *accountId;

/**
 @discussion 设备物理地址
 @property macAddress
 */
@property (nonatomic,copy,readonly)  NSString *macAddress;

/**
 @discussion 00表示空闲 01表示有订单在进行 02表示刷卡消费 03表示消费完成数据没采集
 @property onCharge
 */
@property (nonatomic,copy,readonly)  NSNumber *onCharge;

/**
 @discussion 设备故障信息
 @property status
 */
@property (nonatomic,copy,readonly)  NSNumber *status;

/**
 @discussion 交易校验随机数,用于下发费率
 @property tacTimes
 */
@property (nonatomic,copy,readonly) NSString *tacTimes;
/**
 1 大类(0:水表，1:饮水机，2:洗衣机，3:吹风机，4 充电 器 5空调)
 
 @property maxType
 */
@property (nonatomic,copy,readonly) NSNumber *maxType;
/**
 2 小类 (0-9 子类)
 @property minType
 */
@property (nonatomic,copy,readonly) NSNumber *minType;
/**
 大小类组合十六进制
 @property macType
 */
@property (nonatomic,copy,readonly) NSString *macType;
/**
 @discussion 计费方式 0x00水控计时， 0x01操作计时，0x02操作计量， 0x03电控计时，0x04电控计量 ， 0x11水控计量 ，0x21洗衣模式-标准冼，0x22洗衣模式-快速洗，0x23洗衣模式-单脱水，0x24洗衣模式-大件洗
 @property chargeMethod
 */
@property (nonatomic,copy,readonly) NSNumber *chargeMethod;
/**
 @discussion 订单已使用时间分钟
 @property macTime
 */
@property (nonatomic,copy,readonly) NSNumber *macTime;

/**
 @discussion 软件版本号
 @property verSoft
 */
@property (nonatomic,copy,readonly) NSNumber *verSoft;
/**
 @discussion 通信版本：0x00 - 0x20 默认0x10
 @property commMode
 */
@property (nonatomic,copy,readonly) NSString *commMode;
/**
 @discussion 卡交易总额 （1000厘=1元）
 @property cardmoney
 */
@property (nonatomic,copy,readonly) NSNumber *cardmoney;
/**
 @discussion 密钥编号 从00开始一共50组
 @property deviceType
 */
@property (nonatomic,copy,readonly) NSNumber *KEYNO;
/**
 @discussion 功能版本特定值，区分功能 特定值6A用于区分
 @property deviceType
 */
@property (nonatomic,copy,readonly) NSNumber *functionType;
/**
 @discussion 预留字段
 @property reserved 7个字节
 */
@property (nonatomic, strong, readonly) NSData *reserved;


/**x
 @discussion 解析设备状态数据
 
 @param data 设备状态数据
 @return <code>KRStateObject</code>对象，如果data为<i>nil</i>,返回空
 */
+ (instancetype)stateObjectWithDetailsFromData:(NSData *)data;
@end




#pragma mark - KRConsumptionDetailsObject

/**
 @class KRConsumptionDetailsObject
 @discussion 消费详情数据，
 */
@interface KRConsumptionDetailsObject : NSObject

/**
 @discussion 时间序号
 @property timeId
 */
@property (nonatomic,copy,readonly)  NSString *timeId;

/**
 @discussion 姓名编号
 @property productId
 */
@property (nonatomic,copy,readonly)  NSNumber *productId;

/**
 @discussion 设备id
 @property deviceId
 */
@property (nonatomic,copy,readonly)  NSNumber *deviceId;

/**
 @discussion 账号id
 @property accountId
 */
@property (nonatomic,copy,readonly)  NSNumber *accountId;

/**
 @discussion 账户类别 1：管理员 2：普通用户
 @property accountType
 */
@property (nonatomic,copy,readonly)  NSNumber *accountType;

/**
 @discussion 账号使用次数
 @property useCount
 */
@property (nonatomic,copy,readonly)  NSNumber *useCount;

/**
 @discussion 预扣金额 5000厘
 @property ykMoney
 */
@property (nonatomic,copy,readonly)  NSNumber *ykMoney;

/**
 @discussion 消费金额
 @property consumeMone
 */
@property (nonatomic,copy,readonly)  NSNumber *consumeMone;

/**
 @discussion 费率
 @property rate
 */
@property (nonatomic,copy,readonly)  NSNumber *rate;

/**
 @discussion Mac物理地址
 @property macAddress
 */
@property (nonatomic,copy,readonly)  NSString *macAddress;


/**
 @discussion 消费脉冲数
 @property pluseNum
 */
@property (nonatomic,copy,readonly)  NSNumber *pluseNum;

/**
 @discussion 水流速（mL/6S）
 @property flowRate
 */
@property (nonatomic,copy,readonly)  NSNumber *flowRate;

/**
 @discussion 使用时长（秒）
 @property useTime
 */
@property (nonatomic,copy,readonly)  NSNumber *useTime;

/**
 @discussion 暂停次数
 @property pauseCnt
 */
@property (nonatomic,copy,readonly)  NSNumber *pauseCnt;

/**
 @discussion 基表累计用水量（单位升，最大42.3亿升水）
 @property totalCapacity
 */
@property (nonatomic,copy,readonly)  NSNumber *totalCapacity;

/**
 @discussion 水表出水温度（0-100度）
 @property waterTemp
 */
@property (nonatomic,copy,readonly)  NSNumber *waterTemp;

/**
 @discussion 密钥编号
 @property keyNo
 */
@property (nonatomic,copy,readonly)  NSNumber *keyNo;

/**
 @discussion 通过当前数据即时计算得到的，每次需验证通过后才能清除数据
 @property tac
 */
@property (nonatomic,copy,readonly)  NSString *tac;

/**
 @discussion 消费的二进制数据
 @property xfData
 */
@property (nonatomic,copy,readonly)NSData *xfData;
/**
 @discussion 解析消费详情数据
 
 @param data 消费详情
 @return <code>KRConsumptionDetailsObject</code>对象，如果data为<i>nil</i>,返回空
 */
+ (instancetype)consumptionDetailsObjectWithDetailsFromData:(NSData *)data;
@end
