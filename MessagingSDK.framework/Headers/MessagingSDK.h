//
//  MessagingSDK.h
//  MessagingSDK
//
//  Created on 7/21/15.
//  Copyright (c) 2015 Loment. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for MessagingSDK.
FOUNDATION_EXPORT double MessagingSDKVersionNumber;

//! Project version string for MessagingSDK.
FOUNDATION_EXPORT const unsigned char MessagingSDKVersionString[];

// Errors
#import <MessagingSDK/CNMErrorCodes.h>

// Services
#import <MessagingSDK/CNMCryptoServices.h>
#import <MessagingSDK/CNMUserServices.h>
#import <MessagingSDK/CNMMessagingServices.h>
#import <MessagingSDK/CNMMessageDefaultsServices.h>

// FRC like delivery
#import <MessagingSDK/CNMContentDeliveryController.h>

// User Layer Model objects
#import <MessagingSDK/CNMUser.h>
#import <MessagingSDK/CNMCashewAccount.h>
#import <MessagingSDK/CNMDevice.h>

// Messaging Layer Model Objects
#import <MessagingSDK/CNMConversation.h>
#import <MessagingSDK/CNMMessage.h>
#import <MessagingSDK/CNMContact.h>
#import <MessagingSDK/CNMAttachment.h>
#import <MessagingSDK/CNMOutgoingContact.h>
#import <MessagingSDK/CNMIncomingContact.h>

/**
 *  Object represents SDK entry point.
 */

@interface MessagingSDK : NSObject

/**
 *  Helper method to return version string from framework bundle
 *
 *  @return version number
 */
+ (NSString *) getVersion;

@end
