//
//  CNMUser.h
//  MessagingSDK
//
//  Created on 7/24/15.
//  Copyright (c) 2015 Loment. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CNMDevice;

/**
 *  Object represents a Loment user in the Loment system.
 */
@interface CNMUser : NSObject

/**
 *  The Loment user's name
 */
@property (nullable, nonatomic, strong, readonly) NSString *userName;

/**
 *  The Loment user's email
 */
@property (nullable, nonatomic, strong, readonly) NSString *userEmail;

/**
 *  The Loment user's mobile phone
 */
@property (nullable, nonatomic, strong, readonly) NSString *userPhone;

/**
 *  The Loment user's device
 */
@property (nullable, nonatomic, strong, readonly) CNMDevice * device;

/**
 *  The Loment user's set of cashew account
 */
@property (nullable, nonatomic, strong, readonly) NSArray *cashewAccounts;

/**
 *  The users password
 */
@property (nullable, nonatomic, strong, readonly) NSString *password;

@end