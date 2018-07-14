//
//  CNMMessage.h
//  MessagingSDK
//
//  Created on 8/4/15.
//  Copyright (c) 2015 Loment. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CNMMessageEnums.h"

@class CNMConversation;
@class CNMContact;
@class CNMAttachment;

/**
 *  Object represents a message object in the Loment system.
 */
@interface CNMMessage : NSObject

/**
 *  Indicates whether the message can be forwarded
 */
@property (nonatomic, assign, readonly) BOOL forwardRestricted;

/**
 *  The priority of a message (low, medium, high, highest)
 */
@property (nonatomic, assign, readonly) MessagePriorityLevel priority;

/**
 *  The unique id for the message, assigned by the server
 */
@property (nullable, nonatomic, strong, readonly) NSString * serverId;

/**
 *  The current status of the message (pending, failed, sent, read)
 */
@property (nonatomic, assign, readonly) MessageStatus status;

/**
 *  Current state of acknowledgement. @See AcknowledgementState
 */
@property (nonatomic, assign, readonly) AcknowledgementState acknowledgement;

/**
 *  The time at which the message was created
 */
@property (nonnull, nonatomic, strong, readonly) NSDate * timestamp;

/**
 *  The number of minutes between the message being viewed and expiring (-1 if the message does not expire)
 */
@property (nonatomic, assign, readonly) NSInteger expiryMinutes;

/**
 *  The date at which the message expires, nil if the message does not expire.
 */
@property (nullable, nonatomic, strong, readonly) NSDate * expiryDate;

/**
 *  The date at which the message schedule time, nil if the message does not sending delay.
 */
@property (nullable, nonatomic, strong, readonly) NSString * scheduleTime;

/**
 *  The sender of the message
 */
@property (nullable, nonatomic, strong, readonly) CNMContact * sender;

/**
 *  The conversation that the message belongs to
 */
@property (nullable, nonatomic, weak, readonly) CNMConversation * conversation;

/**
 *  If message contains an attachment this value will be present. See CNMAttachment for details on how to extract attachment information
 */
@property (nullable, nonatomic, strong, readonly) CNMAttachment * attachment;

/**
 *  The message in plain text
 */
@property (nullable, nonatomic, strong, readonly) NSString * content;

@property (nonatomic, assign, readonly) NSInteger msgType;

@end
