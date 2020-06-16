//
//  KRWMDefine.h
//  KRoadWaterMeter
//
//  Created by 远征 马 on 2017/5/5.
//  Copyright © 2017年 马远征. All rights reserved.
//

#import <UIKit/UIKit.h>

#ifndef KRWMDefine_h
#define KRWMDefine_h

/**
 @enum KRManagerState
 @discussion 蓝牙状态定义
 */
typedef NS_ENUM(NSInteger, KRManagerState) {
    /*! 未知错误*/
    KRManagerStateUnknown,
    /*! 蓝牙重置状态*/
    KRManagerStateResetting,
    /*! 设备不支持状态*/
    KRManagerStateUnsupported,
    /*! 设备未授权状态*/
    KRManagerStateUnauthorized,
    /*! 蓝牙关闭*/
    KRManagerStatePoweredOff,
    /*! 蓝牙打开*/
    KRManagerStatePoweredOn,
};


/**
 @enum KRErrorCode
 @discussion 水表数据响应错误码
 */
typedef NS_ENUM (NSInteger, KRErrorCode)
{
    /*! 未知错误*/
    KRErrorCodeUnknownError = 0xFF,
    /*! 包头错误*/
    KRErrorCodePackageHeaderError = 0x01,
    /*! 包长度错误*/
    KRErrorCodePackageLengthError = 0x02,
    /*! 未采集消费数据*/
    KRErrorCodeNotClearConsumptionDetailsError = 0x03,
    /*! 功能码错误*/
    KRErrorCodeFunctionCodeError = 0x04,
    /*! 数据格式错误*/
    KRErrorCodeDataFormatError = 0x05,
    /*! 校验和错误*/
    KRErrorCodeCheckSumError = 0x06,
    /*! 结束码错误*/
    KRErrorCodeEndCodeError = 0x07,
    /*! 来源错误*/
    KRErrorCodeSourceError = 0x08,
    /*! 密钥错误*/
    KRErrorCodeKeyError = 0x08,
};


/*!
 * @enum KRSyncResponseState
 * @discussion  同步响应结果
 */
typedef NS_ENUM(NSInteger, KRSyncResponseState) {
    
    /*! 未知类型*/
    KRSyncResponseStateUnKnown = 0,
    /*! 当前设备不支持蓝牙4.0*/
    KRSyncResponseStateUnsupported = 1,
    /*! 蓝牙未授权*/
    KRSyncResponseStateUnauthorized = 2,
    /*! 蓝牙重置状态*/
    KRSyncResponseStateResetting = 3,
    /*! 蓝牙未连接*/
    KRSyncResponseStateNotConnected = 4,
    /*! 蓝牙关闭，主动关闭蓝牙时回调*/
    KRSyncResponseStatePowerOff = 5,
    /*! 蓝牙断开连接，主动或者被动断开都会调用*/
    KRSyncResponseStateDisconnect = 7,
    /*! 同步参数错误*/
    KRSyncResponseStateParameterError = 8,
    /*! 正在同步，蓝牙正在同步时发起同步操作会返回此结果*/
    KRSyncResponseStateSynchronizing = 9,
    /*! 写数据响应成功*/
    KRSyncResponseStateSuccess = 10,
    /*! 数据校验出错*/
    KRSyncResponseStateCheckSumError = 11,
    /*! 同步响应超时*/
    KRSyncResponseStateTimeOut = 12,
};


/**
 @enum KRSyncType
 @discussion 蓝牙同步类型
 */
typedef NS_ENUM (NSInteger, KRSyncType)
{
    /*! 未知同步类型*/
    KRSyncTypeUnknown = 0,
    /*! 清楚设备项目信息*/
    KRSyncTypeClearNumInfo = 1,
    /*!  设置和读取设备类型*/
    KRSyncTypeReadingNumInfo = 2,
    /*! 下发项目编号*/
    KRSyncTypeAssignNumber = 3,
    /*! 下发费率参数*/
    KRSyncTypeAssginRate = 4,
    /*! 结束消费指令*/
    KRSyncTypeEndConsumption = 5,
    /*! 查询设备状态*/
    KRSyncTypeGetStateOfDevice = 6,
    /*! 获取消费详情*/
    KRSyncTypeGetConsumptionDetails = 7,
    /*! 清除消费详情*/
    KRSyncTypeClearConsumptionDetails = 8,
    /*! 开始交易*/
    KRSyncTypeTransactionRateForDetails = 9,
    /*! 结束交易*/
    KRSyncTypeEndTransactionMacType = 10,
    /*! 设置密钥*/
    KRSyncTypeSetKye1_1 = 11,
    /*! 结束交易*/
    KRSyncTypeEndWaterTransactionMacType = 12,
    /*! 交易开始(电控设备)*/
    KRSyncTypeElectricTransactionRateForDetails = 13,
    /*! 同步结束*/
    KRSyncTypeEnd = 14,
};

#endif /* KRWMDefine_h */
