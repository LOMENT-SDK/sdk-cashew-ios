//
//  CNMMessageDefaultsServices.h
//  MessagingSDK
//
//  Created on 9/4/15.
//  Copyright (c) 2015 Loment. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CNMMessageEnums.h"

/**
 *  This class provides the ability to set / get defaults for sending a message. If you call send message without the explicit attributes
 * parameters, what is stored in defaults here is what will be used. 
 *
 * Defaults are:
 *   Priority            : Low
 *   Ack Required        : NO
 *   Forward Restricted  : NO
 *   Expiration Duration : -1 (Meaning no expiration)
 *
 *
 * WARNING: Calling any of these methods before calling startServiceForCashewAccount:user:withCompletion:serviceInteruption: on CNMMessagingServices will
 * cause your application to crash. This class needs to ensure you are successfully logged in and running messaging services
 */
@interface CNMMessageDefaultsServices : NSObject

#pragma mark Getters

/**
 *  Retrieves global acknowledgementRequired value
 *
 *  @param error Error reference in case something goes wrong. If error is return, ignore return value
 *
 *  @return Requires acknowledgement
 */
+ (BOOL)isAcknowledgementRequired:(NSError * __autoreleasing *)error;

/**
 *  Retrieves global forward restricted value
 *
 *  @param error Error reference in case something goes wrong. If error is return, ignore return value
 *
 *  @return Restricted forwarding
 */
+ (BOOL)isForwardingRestricted:(NSError * __autoreleasing *)error;

/**
 *  Retrieves global priority value
 *
 *  @param error Error reference in case something goes wrong. If error is return, ignore return value
 *
 *  @return Message priority level
 */
+ (MessagePriorityLevel)priorityLevel:(NSError * __autoreleasing *)error;

/**
 *  Retrieves global expiration value
 *
 *  @param error Error reference in case something goes wrong. If error is return, ignore return value
 *
 *  @return Expiration duration in minutes
 */
+ (NSInteger)expirationDurationMinutes:(NSError * __autoreleasing *)error;

#pragma mark Setters

/**
 *  Sets global acknowledgementRequired value
 *
 *  @param error Error reference in case something goes wrong.
 *
 *  @param acknowledgementRequired New value
 */
+ (BOOL)setAcknowledgementRequired:(BOOL)acknowledgementRequired error:(NSError * __autoreleasing *)error;

/**
 *  Sets global forward restricted value
 *
 *  @param error Error reference in case something goes wrong.
 *
 *  @param forwardingRestricted New value
 */
+ (BOOL)setForwardingRestricted:(BOOL)forwardingRestricted error:(NSError * __autoreleasing *)error;

/**
 *  Sets global priority value
 *
 *  @param error Error reference in case something goes wrong.
 *
 *  @param priorityLevel New value
 */
+ (BOOL)setPriorityLevel:(MessagePriorityLevel)priorityLevel error:(NSError * __autoreleasing *)error;

/**
 *  Sets global expiration value
 *
 *  @param error Error reference in case something goes wrong.
 *
 *  @param expirationDurationMinutes New value
 */
+ (BOOL)setExpirationDurationMinutes:(NSInteger)expirationDurationMinutes error:(NSError * __autoreleasing *)error;

@end