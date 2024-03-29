//
//  KRWMBlock.h
//  KRoadWaterMeter
//
//  Created by 远征 马 on 2017/5/5.
//  Copyright © 2017年 马远征. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "KRWMObject.h"
#import "KRWMDefine.h"

#ifndef KRWMBlock_h
#define KRWMBlock_h

/**
 @discussion 蓝牙搜索结果回调

 @param retArray 外设数组
 @param aPeripheral 当前扫描到的蓝牙外设
 */
typedef void (^KRWMPeriphralsHandler)(NSArray<CBPeripheral*> *retArray, CBPeripheral *aPeripheral);


/**
 @discussion 同步数据回调block

 @param syncType 当前同步类型
 @param data 同步的数据
 */
typedef void (^KRWMDataHandler)(KRSyncType syncType, NSData *data , NSString *originalData);


/**
 @discussion 同步结果回调

 @param syncType 当前同步类型
 @param state 同步结果响应状态
 */
typedef void (^KRWMResultHandler)(KRSyncType syncType, KRSyncResponseState state);

/**
 @discussion 连接成功

 @param peripheral 连接外设
 */
typedef void (^KRWMConnectionSuccessfulHandler)(CBPeripheral *peripheral);

/**
 @discussion 连接失败

 @param peripheral 连接外设
 */
typedef void (^KRWMConnectionFailHandler)(CBPeripheral *peripheral);

/**
 @discussion 断开连接

 @param peripheral 连接外设
 */
typedef void (^KRWMDisconnectHandler)(CBPeripheral *peripheral);


#endif /* KRWMBlock_h */
