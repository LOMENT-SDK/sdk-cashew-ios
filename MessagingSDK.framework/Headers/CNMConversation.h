//
//  CNMConversation.h
//  MessagingSDK
//
//  Created on 8/4/15.
//  Copyright (c) 2015 Loment. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CNMMessage;
@class CNMContact;

extern NSString * __nonnull const CNMConversationChangedNotification;
extern NSString * __nonnull const CNMOldConversationKey;
extern NSString * __nonnull const CNMNewConversationKey;


/**
 *  Object represents a conversation object in the Loment system.
 */
@interface CNMConversation : NSObject

#pragma mark - Group Attributes

/**
 *  The groupId of the conversation, provided by the server, only set when the conversation is for a group
 */
@property (nullable, nonatomic, strong, readonly) NSString *groupId;

/**
 *  The groupName of the conversation. The admin of the group sets this on creation, but can also update it.
 */
@property (nullable, nonatomic, strong, readonly) NSString *groupName;

/**
 *  The groupOwner of the conversation. The person who can control group functionality.
 */
@property (nullable, nonatomic, strong, readonly) CNMContact *groupOwner;

#pragma mark - Private Convo Attributes

/**
 *  An unique identifier clearly stating who the conversation is with
 */
@property (nullable, nonatomic, strong, readonly) NSString *participantsString;

#pragma mark - Common Attributes

/**
 *  Returns Features list the group has 
 1 - Restricted Groups (Once group created No operations on Group) , 
 2 - Will get Group messages and Group update messages that were happened after he has added to the group.
 3 - Will get all Group messages and Group update mesaages irrespective of the ime he added to group.
 4 - Every member of group can add participants.
 */
@property (nullable, nonatomic, strong, readonly) NSString *features;

/**
 *  Returns all the participants in the conversation.
 */
@property (nullable, nonatomic, strong, readonly) NSSet * participants;

/**
 *  Returns all the admins in the conversation.
 */
@property (nullable, nonatomic, strong, readonly) NSString * adminString;

/**
 *  The latest message on the conversation
 */
@property (nullable, nonatomic, strong, readonly) CNMMessage * latestMessage;

/**
 *  The time at which the message was updated
 */
@property (nonnull, nonatomic, strong, readonly) NSDate * timestamp;

/**
 *  Returns Current loggedin user cashew ID.
 */
@property (nullable, nonatomic, strong, readonly) NSString * selectedCashewID;


//@property (nullable, nonatomic, strong) NSSet *messages; // Maybe later

/**
 *  Helper method to tell if a conversation is a group or not (aka 1-1 convo, private convo)
 *
 *  @return YES if group, NO otherwise
 */
- (BOOL)isGroup;

/**
 *  Total number of unread messages
 *
 *  @param error        Error referece
 *
 *  @return Total number of unread messsages or NSUIntegerMax if error
 */
- (NSUInteger)numberOfUnreadMessagesError:(NSError * __autoreleasing _Nullable * _Nullable)error;


@end
