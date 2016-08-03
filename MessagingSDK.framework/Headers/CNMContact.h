//
//  CNMContact.h
//  MessagingSDK
//
//  Created on 8/4/15.
//  Copyright (c) 2015 Loment. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Object represents a contact object in the Loment system.
 */
@interface CNMContact : NSObject

/**
 *  The cashewUsername of the contact
 */
@property (nullable, nonatomic, strong, readonly) NSString *cashewUsername;

/**
 *  The phone of the contact
 */
@property (nullable, nonatomic, strong, readonly) NSString *contactPhone;

/**
 *  The contact's name
 */
@property (nullable, nonatomic, strong, readonly) NSString *contactName;

/**
 *  The contact's email
 */
@property (nullable, nonatomic, strong, readonly) NSString *contactEmail;

/**
 *  Helper method that returns YES if the contact represtents the currently logged in CashewAccount
 *
 *  @return YES if this is the account you are logged in as
 */
- (BOOL)isUser;

@end