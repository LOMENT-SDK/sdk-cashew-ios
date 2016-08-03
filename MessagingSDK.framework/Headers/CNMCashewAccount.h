//
//  CNMCashewAccount.h
//  MessagingSDK
//
//  Created on 7/30/15.
//  Copyright (c) 2015 Loment. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Object represents a cashew account in the Loment system. A Loment user may have many of these
 */
@interface CNMCashewAccount : NSObject

/**
 *  Username for a cashew account
 */
@property (nullable, nonatomic, strong, readonly) NSString *cashewUsername;

/**
 *  The unique ID set by server
 */
@property (nullable, nonatomic, strong, readonly) NSString *cashewId;

@end