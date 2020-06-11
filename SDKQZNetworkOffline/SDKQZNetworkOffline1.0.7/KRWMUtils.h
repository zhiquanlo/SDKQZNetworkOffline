//
//  KRWMUtils.h
//  KRoadWaterMeter
//
//  Created by 远征 马 on 2017/5/5.
//  Copyright © 2017年 马远征. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KRWMObject.h"



/**
 @class KRWMUtils
 @discussion 蓝牙数据解析工具
 */
@interface KRWMUtils : NSObject


/**
 @discussion 查询响应结果是否返回正确
 
 @param data 响应数据
 @return YES/NO
 */
+ (BOOL)isSuccessResponseWithData:(NSData*)data;


/**
 @discussion 提取错误码,失败的时候才有响应码
 
 @param data 响应数据
 @return KRErrorCode
 */
+ (KRErrorCode)getErrorCodeFromData:(NSData*)data;

/// 十六进制字符串转NSData
/// @param str 十六进制字符串
+ (NSData *)convertHexStrToData:(NSString *)str;



/**
 @discussion 解析消费详情数据
 
 @param data 消费详情
 @return <code>KRConsumptionDetailsObject</code>对象，如果data为<i>nil</i>,返回空
 */
+ (KRConsumptionDetailsObject*)getConsumptionDetailsFromData:(NSData*)data;


/**
 @discussion 解析设备状态数据
 
 @param data 设备状态数据
 @return <code>KRStateObject</code>对象，如果data为<i>nil</i>,返回空
 */
+ (KRStateObject*)getStateOfDeviceFromData:(NSData*)data;


@end

