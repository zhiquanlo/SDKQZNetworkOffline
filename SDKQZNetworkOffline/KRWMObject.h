//
//  KRWMObject.h
//  KRoadWaterMeter
//
//  Created by 远征 马 on 2017/5/5.
//  Copyright © 2017年 马远征. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KRWMDefine.h"
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
@property (nonatomic, strong)  NSNumber *productId;

/**
 @discussion 设备ID
 @property deviceId
 */
@property (nonatomic, strong)  NSNumber *deviceId;

/**
 @discussion 帐号(1)
 @property accountId
 */
@property (nonatomic, strong)  NSNumber *accountId;

/**
 @discussion 设备物理地址
 @property macAddress
 */
@property (nonatomic, strong)  NSString *macAddress;

/**
 @discussion 00表示空闲 01表示有订单在进行 02表示刷卡消费 03表示消费完成数据没采集
 @property onCharge
 */
@property (nonatomic, strong)  NSNumber *onCharge;

/**
 @discussion 设备故障信息
 @property status
 */
@property (nonatomic, strong)  NSNumber *status;

/**
 @discussion 交易校验随机数,用于下发费率
 @property tacTimes
 */
@property (nonatomic, strong) NSString *tacTimes;
/**
 1 大类(0:水表，1:饮水机，2:洗衣机，3:吹风机，4 充电 器 5空调)
 
 @property MAXType
 */
@property (nonatomic, strong) NSNumber *MAXType;
/**
 2 小类 (0-9 子类)
 @property MINType
 */
@property (nonatomic, strong) NSNumber *MINType;
/**
 大小类组合十六进制
 @property MacType
 */
@property (nonatomic, strong) NSString *MacType;
/**
 @discussion 计费方式 0x00水控计时， 0x01操作计时，0x02操作计量， 0x03电控计时，0x04电控计量 ， 0x11水控计量 ，0x21洗衣模式-标准冼，0x22洗衣模式-快速洗，0x23洗衣模式-单脱水，0x24洗衣模式-大件洗
 @property Constype
 */
@property (nonatomic,strong)NSNumber *ChargeMethod;
/**
 @discussion 订单已使用时间分钟
 @property MacTime
 */
@property (nonatomic,strong)NSNumber *MacTime;

/**
 @discussion 软件版本号
 @property VerSoft
 */
@property (nonatomic,strong)NSNumber *VerSoft;
/**
 @discussion 通信版本：0x00 - 0x20 默认0x10
 @property CommMode
 */
@property (nonatomic,strong)NSString *CommMode;
/**
 @discussion 卡交易总额 （1000厘=1元）
 @property Cardmoney
 */
@property (nonatomic,strong)NSNumber *Cardmoney;
/**
 @discussion 设备类型(1密码水表)
 @property deviceType
 */
@property (nonatomic,strong)NSNumber *deviceType;
/**
 @discussion 预留字段
 @property reserved 9个字节
 */
@property (nonatomic,strong)NSNumber *reserved;
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
@property (nonatomic,strong)  NSString *timeId;

/**
 @discussion 姓名编号
 @property productId
 */
@property (nonatomic,strong)  NSNumber *productId;

/**
 @discussion 设备id
 @property deviceId
 */
@property (nonatomic,strong)  NSNumber *deviceId;

/**
 @discussion 账号id
 @property accountId
 */
@property (nonatomic,strong)  NSNumber *accountId;

/**
 @discussion 账户类别 1：管理员 2：普通用户
 @property accountType
 */
@property (nonatomic,strong)  NSNumber *accountType;

/**
 @discussion 账号使用次数
 @property useCount
 */
@property (nonatomic,strong)  NSNumber *useCount;

/**
 @discussion 预扣金额 5000厘
 @property ykMoney
 */
@property (nonatomic,strong)  NSNumber *ykMoney;

/**
 @discussion 消费金额
 @property consumeMone
 */
@property (nonatomic,strong)  NSNumber *consumeMone;

/**
 @discussion 费率
 @property rate
 */
@property (nonatomic,strong)  NSNumber *rate;

/**
 @discussion Mac物理地址
 @property macAddress
 */
@property (nonatomic,strong)  NSString *macAddress;

/**
 清除消费账单命令，查询消费账单之后发送清除命令成功后水表进入空闲状态
 
 @return 清除消费命令数据
 */
- (NSData*)writeData;
@end
