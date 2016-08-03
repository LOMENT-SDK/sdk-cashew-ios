//
//  CNMOutgoingContact.h
//  MessagingSDK
//
//  Created on 9/22/15.
//  Copyright (c) 2015 Loment. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Status representing different states a suggested contact is in
 */
typedef NS_ENUM(NSUInteger, OutgoingContactRequestStatus){
    /**
     *  You have yet to send a request to this suggestion
     */
    OutgoingContactRequestStatusNotSent,
    /**
     *  You have sent a request, waiting for response
     */
    OutgoingContactRequestStatusSent,
    /**
     *  The suggested contact has accepted, and has been added to contacts
     */
    OutgoingContactRequestStatusAccepted,
    /**
     *  The suggested contact has declined, no information downloaded
     */
    OutgoingContactRequestStatusRejected
};

/**
 *  Simple object representing all suggested contacts
 */
@interface CNMOutgoingContact : NSObject

/**
 *  The name of the suggested friend
 */
@property (nullable, nonatomic, strong, readonly) NSString * name;

/**
 *  The suggested status
 */
@property (nonatomic, assign, readonly) OutgoingContactRequestStatus status;

@end