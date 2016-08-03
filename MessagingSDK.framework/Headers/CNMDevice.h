//
//  CNMDevice.h
//  MessagingSDK
//
//  Created on 7/30/15.
//  Copyright (c) 2015 Loment. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Object represents a device object in the Loment system. Should be at least one valid object after login.
 */
@interface CNMDevice : NSObject

/**
 *  The name of the device
 */
@property (nullable, nonatomic, strong, readonly) NSString *deviceName;

/**
 *  The unique ID set by the server
 */
@property (nullable, nonatomic, strong, readonly) NSString *deviceID;

@end