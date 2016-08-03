//
//  CNMIncomingContact.h
//  MessagingSDK
//
//  Created on 9/22/15.
//  Copyright (c) 2015 Loment. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * __nonnull const CNMIncomingContactNotification;
extern NSString * __nonnull const CNMNumberOfUnansweredRequestsKey;

/**
 *  Status representing different states a friend request send to you is in
 */
typedef NS_ENUM(NSUInteger, IncomingContactRequestStatus){
    /**
     *  You have yet to reply to this request
     */
    IncomingContactRequestStatusNotAnswered,
    /**
     *  You have accepted this friend, their contact information has been added
     */
    IncomingContactRequestStatusAccepted,
    /**
     *  You have declined their invite, no information downloaded
     */
    IncomingContactRequestStatusRejected
};

/**
 *  Simple object representing every friend request someone sent to you
 */
@interface CNMIncomingContact : NSObject

/**
 *  The cashew username of the (potential) friend
 */
@property (nullable, nonatomic, strong, readonly) NSString * cashewUsername;

/**
 *  The name of the (potential) friend
 */
@property (nullable, nonatomic, strong, readonly) NSString * name;

/**
 *  The request status
 */
@property (nonatomic, assign, readonly) IncomingContactRequestStatus status;

@end