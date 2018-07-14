//
//  CNMMessagingServices.h
//  MessagingSDK
//
//  Created on 8/5/15.
//  Copyright (c) 2015 Loment. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CNMMessageEnums.h"

@class CNMMessage;
@class CNMCashewAccount;
@class CNMUser;
@class CNMConversation;
@class CNMContentDeliveryController;
@class CNMContact;
@class CNMOutgoingContact;
@class CNMIncomingContact;
@class CNMAttachment;

#pragma mark - Completion Block Definions

/**
 *  Completion handler for many CNMMessagingServices
 *
 *  @param error error reported if an error occured during messaging service call
 */
typedef void (^CNMMessagingServiceCompletion)(NSError *error);

/**
 *  Completion handler for creating a conversation
 *
 *  @param error error reported if an error occured during messaging service call
 */
typedef void (^CNMMessagingConversationCompletion)(CNMConversation * conversation, NSError *error);

/**
 *  Completion handler for creating a contact
 *
 *  @param error error reported if an error occured during messaging service call
 */
typedef void (^CNMMessagingContactCompletion)(CNMContact * contact, NSError *error);

/**
 *  Completion handler for searching for suggested contacts
 *
 *  @param error error reported if an error occured during search service call
 */
typedef void (^CNMMessagingContactSearchCompletion)(NSArray * outgoingContacts, NSError *error);

/**
 *  Completion handler for retrieving all friend requests sent to you. Note: Includes those you've accepted / declined. Please check status of 
 * individual requests 
 *
 * @see CNMIncomingContact
 *
 *  @param error error reported if an error occured during retrieval
 */
typedef void (^CNMMessagingContactRequestCompletion)(NSArray * friendRequest, NSError *error);

/**
 *  Completion handler for sending contact request
 *
 *  @param contact The update CNMOutgoingContact
 *  @param error   error reported if an error occured during contact request service call
 */
typedef void (^CNMMessagingSendContactRequestCompletion)(CNMOutgoingContact * contact, NSError *error);

/**
 *  Completion handler for accepting or declining a contact request
 *
 *  @param incomingContact  The CNMIncomingContact accepted or declined
 *  @param error            error reported if an error occured during accepting or declining the contact request
 */
typedef void (^CNMMessagingContactRequestResponseCompletion)(CNMIncomingContact *incomingContact, NSError *error);

/**
 *  Completion block for calling asynchronous download of attachment.
 *
 *  @param data    Plain data if found
 *  @param error   Error if present
 */
typedef void(^CNMAttachmentDownloadComplete)(NSData * data, NSError * error);

/**
 *  Progress block called periodically when attachments are uploaded/downloaded
 *
 *  @param currentBytesTransferred Current bytes transferred
 *  @param totalBytesToTransfer    Total bytes expexted to be transferred
 */
typedef void (^CNMAttachmentTransferProgress)(NSUInteger currentBytesTransferred, NSUInteger totalBytesToTransfer);

#pragma mark - CNMMessagingServicesListener Protocol

/**
 *  Listener / hook object that is notified when messaging services stop / starts. Useful for cleaning up and setting up after stop / start.
 * Especially with contentDeliveryControllers
 */
@protocol CNMMessagingServicesListener <NSObject>

@required
/**
 *  Called when started
 */
- (void)didStopServices;

/**
 *  Called when stopped
 */
- (void)didStartServices;

@end

#pragma mark - CNMMessagingServices Interface

/**
 *  Public interface for SDK user, allowing them to send and receive messages, create groups, create contacts, and all other things messaginging related.
 * 
 * This API is only useful after you successfully authenticate with Loment server in the UserServices class and the user has selected a CNMCashewAccount
 * they wish to start messaging with.
 *
 * After that has been achieved call startServiceForCashewAccount:user:withCompletion:serviceInteruption to begin all messaging services. When you are done,
 * be sure to clean up by calling stop.
 *
 * See sample project for example
 *
 * Note: All other messaging API calls will fail to work until you successfully start services.
 *
 */
@interface CNMMessagingServices : NSObject

#pragma mark - Life Cycle

/**
*  Starts the messaging service so you can start sending and receiving messages
*
*  @param cashewAccount The cashew account to use
*  @param user          The loment user associated with the cashew account
*  @param completion    completion handler that is called when we are finished trying to start the service
*  @param interuption   If service is interupted for any reason, this block is called. Recommendation is to call stop service before calling start again
*/
+ (void)startServiceForCashewAccount:(CNMCashewAccount *)cashewAccount user:(CNMUser *)user withCompletion:(CNMMessagingServiceCompletion)completion serviceInteruption:(CNMMessagingServiceCompletion)interuption;

/**
 *  Stops the messaging service so you can start sending and receiving messages. Subsequently all other calls other than start are guarenteed to fail
 * until you start up services again. As a special reminder, all CNMContentDeliveryController will cease to provide updates.
 *
 *  @param completion completion handler that is called when we are finished stopping the service
 */
+ (void)stopServiceWithCompletion:(CNMMessagingServiceCompletion)completion;

/**
 *  Registers a new listener to listen for start / stop
 *
 *  @param listener The object that wants to listen
 */
+ (void)registerNewListener:(NSObject <CNMMessagingServicesListener> *)listener;

/**
 *  Unregisters the specified listener
 *
 *  @param listener The object that no longer wants updates
 */
+ (void)unregisterListener:(NSObject <CNMMessagingServicesListener> *)listener;

#pragma mark - Message Calls

/**
 *  Sends a new message from the user on the specified conversation. Uses settings stored in global settings. See CNMSettingsServices, defaults can be changed here.
 *  To send a message with one-time settings call sendNewMessage:options:withExpirationDuration:forConversation:withCompletion
 *
 *
 *  @param plainText            Plain text message
 *  @param conversation         The conversation to post on
 *  @param msgType              Type of message (1- Normal messages, 2- Welcome message, 3- Contact, 4- Old Groups , 5- Auto Response , 6- New Groups , 7 - Screen Shot )  
 *  @param completion           Completion handler that is called when we are finished sending
 */

+ (void)sendNewMessage:(NSString *)plainText forConversation:(CNMConversation *)cnmConversation withType:(NSInteger)msgType withCompletion:(CNMMessagingServiceCompletion)completion;

+ (void)sendNewMessage:(NSString *)plainText withScheduleTime:(NSDate *)scheduleTime forConversation:(CNMConversation *)cnmConversation withType:(NSInteger)msgType withCompletion:(CNMMessagingServiceCompletion)completion;

/**
 *  Sends a new message from the user on the specified conversation with an attachment. Uses settings stored in global settings. See CNMSettingsServices, defaults can be changed here.
 *  To send a message with one-time settings call sendNewMessage:withAttachmentFilename:withAttachmentData:options:withExpirationDuration:forConversation:withCompletion
 *
 *
 *  @param plainText                    Plain text message
 *  @param attachmentFilename           The filename of the attachment
 *  @param attachmentData               The NSData contents of the file
 *  @param conversation                 The conversation to post on
 *  @param msgType              Type of message (1- Normal messages, 2- Welcome message, 3- Contact, 4- Old Groups , 5- Auto Response , 6- New Groups , 7 - Screen Shot )
 *  @param attachmentTransferProgress   Periodic called block during the time the attachment is uploaded
 *  @param completion                   Completion handler that is called when we are finished sending
 */

+ (void)sendNewMessage:(NSString *)plainText withAttachmentFilename:(NSString *)attachmentFilename withAttachmentData:(NSData *)attachmentData withScheduleTime:(NSDate *)scheduleTime forConversation:(CNMConversation *)conversation withType:(NSInteger)msgType withAttachmentTransferProgress:(CNMAttachmentTransferProgress)attachmentTransferProgress withCompletion:(CNMMessagingServiceCompletion)completion;

/**
 *  Sends a new message from the user on the specified conversation with customized settings.
 *
 *  @param plainText            Plain text message
 *  @param options              Bit mask of options to set on a message
 *  @param expirationDuration   Expiration in minutes. Valid values are 1-999. Passing anything else assumes no expiration.
 *  @param conversation         The conversation to post on
*  @param msgType              Type of message (1- Normal messages, 2- Welcome message, 3- Contact, 4- Old Groups , 5- Auto Response , 6- New Groups , 7 - Screen Shot )  
 *  @param completion           Completion handler that is called when we are finished sending
 */

+ (void)sendNewMessage:(NSString *)plainText withScheduleTime:(NSDate *)scheduleTime options:(CNMMessageOptions)options withExpirationDuration:(NSInteger)expirationDuration forConversation:(CNMConversation *)cnmConversation withType:(NSInteger)msgType withCompletion:(CNMMessagingServiceCompletion)completion;

/**
 *  Sends a new message from the user on the specified conversation with an multiple attachments and customized settings.
 *
 *  @param plainText                    Plain text message
 *  @param attachmentFilename           The filename of the attachment
 *  @param attachmentData               The NSData contents of the file
 *  @param scheduleTime                 The time and date of the message 
 *  @param options                      Bit mask of options to set on a message
 *  @param expirationDuration           Expiration in minutes. Valid values are 1-999. Passing anything else assumes no expiration.
 *  @param conversation                 The conversation to post on
 *  @param msgType              Type of message (1- Normal messages, 2- Welcome message, 3- Contact, 4- Old Groups , 5- Auto Response , 6- New Groups , 7 - Screen Shot ) 
 *  @param attachmentTransferProgress   Periodic called block during the time the attachment is uploaded
 *  @param completion                   Completion handler that is called when we are finished sending
 */

+ (void)sendNewMessage:(NSString *)plainText withAttachmentFilename:(NSString *)attachmentFilename withAttachmentData:(NSData *)attachmentData withScheduleTime:(NSDate *)scheduleTime options:(CNMMessageOptions)options withExpirationDuration:(NSInteger)expirationDuration forConversation:(CNMConversation *)cnmConversation withType:(NSInteger)msgType withAttachmentTransferProgress:(CNMAttachmentTransferProgress)attachmentTransferProgress withCompletion:(CNMMessagingServiceCompletion)completion;


+ (void)sendNewMessage:(NSString* )plainText withAttachmentFilenames:(NSArray* )attachmentFilenames withAttachmentsData:(NSArray* )attachmentsData withScheduleTime:(NSDate *)scheduleTime options:(CNMMessageOptions)options withExpirationDuration:(NSInteger)expirationDuration forConversation:(CNMConversation* )conversation withType:(NSInteger)msgType withAttachmentTransferProgress:(CNMAttachmentTransferProgress)attachmentTransferProgress withCompletion:(CNMMessagingServiceCompletion)completion;


+ (void)sendNewMessage:(NSString* )plainText withAttachmentFilenames:(NSArray* )attachmentFilenames withAttachmentsData:(NSArray* )attachmentsData options:(CNMMessageOptions)options withExpirationDuration:(NSInteger)expirationDuration forConversation:(CNMConversation* )conversation withType:(NSInteger)msgType withAttachmentTransferProgress:(CNMAttachmentTransferProgress)attachmentTransferProgress withCompletion:(CNMMessagingServiceCompletion)completion;

/**
 *  Mark a message as read
 *
 *  @param message    The message to mark
 *  @param completion completion handler that is called when we are finished sending
 */
+ (void)markMessageAsRead:(CNMMessage *)message withCompletion:(CNMMessagingServiceCompletion)completion;

/**
 *  Mark a message as acknowledged when the sender requires it
 *
 *  @param message    The message to mark
 *  @param completion completion handler that is called when we are finished sending
 */
+ (void)markMessageAsAcknowledged:(CNMMessage *)message withCompletion:(CNMMessagingServiceCompletion)completion;
/**
 *  Mark a message as deleted. Once the server returns to us that it has been successfully deleted, it will be removed from the app completely.
 *
 * Note: Please wait for completion block to return with success or failure before attempting to call this again
 *
 *  @param message    The message to mark
 *  @param completion completion handler that is called when we are finished updating message
 */
+ (void)markMessageAsDeleted:(CNMMessage *)message withCompletion:(CNMMessagingServiceCompletion)completion;
#pragma mark - Attachments

/**
 *   Call this method to download data. If data is already downloaded, it will fetch from cache on disk
 *
 *  @param cnmAttachment                The attachment to download data on
 *  @param attachmentTransferProgress   Periodic called block during the time the attachment is downloaded
 *  @param downloadComplete             Completion block
 */
+ (void)downloadAttachment:(CNMAttachment *)cnmAttachment withAttachmentTransferProgress:(CNMAttachmentTransferProgress)attachmentTransferProgress withCompletion:(CNMAttachmentDownloadComplete)downloadComplete;

#pragma mark - Add Contact / Create conversations

/**
 *  Add a contact to list of known contacts. If contact does not exist in Loment system, you will get an error back
 *
 *  @param cashewUsername The cashew username to look up
 *  @param completion     Completion block that returns CNMContact or an error if something went wrong
 */
+ (void)addContact:(NSString *)cashewUsername withCompletion:(CNMMessagingContactCompletion)completion;
/**
 *  Add a contact to list of known contacts. If contact does not exist in Loment system, you will get an error back
 *
 *  @param cashewUsername The cashew username to look up
 
 *  @param completion     Completion block that returns CNMContact or an error if something went wrong
 */
+ (void)addContact:(NSString *)cashewUsername contactName:(NSString *)contactString contactEmail:(NSString *)contactEmail contactphone:(NSString *)ContactPhone withCompletion:(CNMMessagingContactCompletion)completion;

/**
 *  Creates a new 1-to-1 CNMConversation and saves it to the database.
 *
 *  @param otherCashewContact  Cashew contact representing the other person
 *  @param completion          Completion block that returns CNMConversation or an error if something went wrong
 */
+ (void)createNewConversationWithOtherCashewContact:(CNMContact *)otherCashewContact withCompletion:(CNMMessagingConversationCompletion)completion;

/**
 *  Creates a new group conversation with the given name using the array of CNMContacts. Caller is the admin / owner of the newly created group.
 *
 *  @param groupName     The name of the group (This param is required)
 *  @param otherContacts Array of valid CNMContacts. If you instantiate your CNMContact, unexpected results may happen.
 *  @param completion    Completion block that returns CNMConversation or an error if something went wrong
 */
+ (void)createNewGroupConversation:(NSString *)groupName withContacts:(NSArray *)otherContacts withCompletion:(CNMMessagingConversationCompletion)completion;

/**
 *  Updates the conversation by adding contacts to group
 *
 *  @param conversation The group conversation you wish to update
 *  @param addMembers   Array of valid CNMContacts. If you instantiate your CNMContact, unexpected results may happen.
 *  @param completion   Completion block that returns CNMConversation or an error if something went wrong
 */
+ (void)updateConversation:(CNMConversation *)conversation addMembers:(NSArray *)addMembers withCompletion:(CNMMessagingConversationCompletion)completion;

/**
 *  Updates the conversation by removing contacts from group
 *
 *  @param conversation  The group conversation you wish to update
 *  @param removeMembers Array of valid CNMContacts
 *  @param completion    Completion block that returns CNMConversation or an error if something went wrong
 */
+ (void)updateConversation:(CNMConversation *)conversation removeMembers:(NSArray *)removeMembers withCompletion:(CNMMessagingConversationCompletion)completion;

/**
 *  Updates the conversation by changing the group name
 *
 *  @param conversation The group conversation you wish to update
 *  @param newGroupName New name of the group
 *  @param completion   Completion block that returns CNMConversation or an error if something went wrong
 */
+ (void)updateConversation:(CNMConversation *)conversation newName:(NSString *)newGroupName withCompletion:(CNMMessagingConversationCompletion)completion;
/**
 *  Updates the conversation by changing the Features status to all members belonging to the group can add members.
 *
 *  @param conversation The group conversation you wish to update
 *  @param completion   Completion block that returns CNMConversation or an error if something went wrong
 */
+ (void)updateConversationFeaturesAdded:(CNMConversation *)cnmConversationParam withCompletion:(CNMMessagingConversationCompletion)completion;

/**
 *  Updates the conversation by changing the Feature Status to only Main Admin and Admin can add members to group
 *
 *  @param conversation The group conversation you wish to update
 *  @param completion   Completion block that returns CNMConversation or an error if something went wrong
 */
+ (void)updateConversationFeaturesRemoved:(CNMConversation *)cnmConversationParam withCompletion:(CNMMessagingConversationCompletion)completion;

/**
 *  Updates the conversation by changing the group Mainadmin
 *
 *  @param conversation The group conversation you wish to update
 *  @param newOwner     The new owner
 *  @param completion   Completion block that returns CNMConversation or an error if something went wrong
 */
+ (void)updateConversation:(CNMConversation *)conversation newOwner:(CNMContact *)newOwner withCompletion:(CNMMessagingConversationCompletion)completion;

/**
 *  For participants of groups that are not the admin but wish to leave a group conversation. Call this method to remove yourself.
 * NOTE: Historical data is kept, you will simply not receive new information on said conversation.
 *
 *  @param conversation The conversation you wish to leave
 *  @param completion   Completion block that returns CNMConversation or an error if something went wrong
 */
+ (void)leaveConversation:(CNMConversation *)conversation withCompletion:(CNMMessagingConversationCompletion)completion;

/**
 *  Updates the conversation by changing the group Member to Admin's
 *
 *  @param conversation The group conversation you wish to update
 *  @param addAdmins    Array of valid CNMContacts
 *  @param completion   Completion block that returns CNMConversation or an error if something went wrong
 */

+ (void)updateConversation:(CNMConversation *)cnmConversationParam addAdmins:(NSArray *)adminsToAdd withCompletion:(CNMMessagingConversationCompletion)completion;

/**
 *  Updates the conversation by changing the group Admin's to Members
 *
 *  @param conversation The group conversation you wish to update
 *  @param removeAdmins Array of valid CNMContacts
 *  @param completion   Completion block that returns CNMConversation or an error if something went wrong
 */

+ (void)updateConversation:(CNMConversation *)cnmConversationParam removeAdmins:(NSArray *)removeAdmins withCompletion:(CNMMessagingConversationCompletion)completion;

+ (void)getGroupConfig:(CNMConversation *)cnmConversationParam;
+ (void)getGroupConfig:(NSString *)groupId withCompletion:(CNMMessagingConversationCompletion)completion;

#pragma mark - Delivery Calls

/**
 *  Retrieves the number of unread messages on any given conversation
 *
 *  @param conversation The conversation in question
 *  @param error        Error referece
 *
 *  @return The undread count or NSUIntegerMax if error
 */
+ (NSUInteger)numberOfUnreadMessagesOnConversation:(CNMConversation *)conversation error:(NSError * __autoreleasing *)error;

/**
 *  Total number of unread messages
 *
 *  @param error        Error referece
 *
 *  @return Total number of unread messsages or NSUIntegerMax if error
 */
+ (NSUInteger)numberOfUnreadMessagesError:(NSError * __autoreleasing *)error;

/**
 *  Provides access to all messages in a conversation in an FRC-like fashion. Be sure to set delegate
 *
 * Important! Only call this on main thread. Reminder! If stopServiceWithCompletion is called, updates will stop.
 *
 *  @param conversation Conversation we wish to track
 *  @param error        Error referece
 *
 *  @return Newly allocated delivery controller
 */
+ (CNMContentDeliveryController *)messagesDeliveryController:(CNMConversation *)conversation error:(NSError * __autoreleasing *)error;

/**
 *  Provides access to all conversations in a FRC-like fashion. Be sure to set delegate
 *
 * Important! Only call this on main thread. Reminder! If stopServiceWithCompletion is called, updates will stop.
 *
 *  @param error        Error reference
 *
 *  @return Newly allocated delivery controller
 */
+ (CNMContentDeliveryController *)allConversationsDeliveryController:(NSError * __autoreleasing *)error;

/**
 *  Provides access to group conversations in a FRC-like fashion. Be sure to set delegate
 *
 * Important! Only call this on main thread. Reminder! If stopServiceWithCompletion is called, updates will stop.
 *
 *  @param error        Error reference
 *
 *  @return Newly allocated delivery controller
 */
+ (CNMContentDeliveryController *)groupConversationsDeliveryController:(NSError * __autoreleasing *)error;

/**
 *  Provides access to contacts in a FRC-like fashion. Be sure to set delegate
 *
 * Important! Only call this on main thread. Reminder! If stopServiceWithCompletion is called, updates will stop.
 *
 *  @param error Error reference
 *
 *  @return Newly allocated delivery controller
 */
+ (CNMContentDeliveryController *)allContactsDeliveryController:(NSError * __autoreleasing *)error;

#pragma mark - Friends and Search for Contacts

/**
 *  Searches for suggested contacts based on provided email addresses and phone numbers
 *
 *  @param emailAddresses   An array of email addresses with which to search
 *  @param phoneNumbers     An array of phone numbers with which to search
 *  @param completion       Completion handler that is called when we are finished sending
 */
+ (void)searchForContactsWithEmailAddresses:(NSArray *)emailAddresses andPhoneNumbers:(NSArray *)phoneNumbers withCompletion:(CNMMessagingContactSearchCompletion)completion;

/**
 *  Asynchronously fetches all your CNMIncomingContacts a.k.a. "Incoming Friend Requests"  Note: Includes those you've accepted / declined. Please check status of
 * individual requests
 *
 *  @param completion Completion block called when data is retrieved
 */
+ (void)allContactRequestsCompletion:(CNMMessagingContactRequestCompletion) completion;

/**
 *  Initiates a new friend request for the given suggested contact.
 *
 *  @param outgoingContact  The outgoing contact we wish to be-friend as a contact
 *  @param completion       Completion block called when request is sent to server
 */
+ (void)sendContactRequestOnOutgoingContact:(CNMOutgoingContact *)outgoingContact withCompletion:(CNMMessagingSendContactRequestCompletion) completion;

/**
 *  Accept a contact request from a CNMIncomingContact
 *
 *  @param incomingContact  The CNMIncomingContact to accept
 *  @param completion       Completion block called once the contact request has been accepted.
 */
+ (void)acceptContactRequest:(CNMIncomingContact *)incomingContact withCompletion:(CNMMessagingContactRequestResponseCompletion)completion;

/**
 *  Decline a contact request from a CNMIncomingContact
 *
 *  @param incomingContact The CNMIncomingContact to decline
 *  @param completion       Completion block called once the contact request has been declined.
 */
+ (void)rejectContactRequest:(CNMIncomingContact *)incomingContact withCompletion:(CNMMessagingContactRequestResponseCompletion)completion;

@end
