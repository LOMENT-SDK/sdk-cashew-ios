//
//  CNMMessageEnums.h
//  MessagingSDK
//
//  Created on 8/17/15.
//  Copyright (c) 2015 Loment. All rights reserved.
//

/**
 *  The different possibilities for message priorities
 */
typedef NS_ENUM(NSUInteger, MessagePriorityLevel){
    /**
     *  Highest priority
     */
    MessagePriorityLevelHighest = 0,
    /**
     *  High priority
     */
    MessagePriorityLevelHigh    = 1,

    /**
     *  Medium priority
     */
    MessagePriorityLevelMedium  = 2,
    /**
     *  Low priority
     */
    MessagePriorityLevelLow     = 3,
};

/**
 *  The different possibilities for a message's status
 */
typedef NS_ENUM(NSUInteger, MessageStatus){
    /**
     *  Message is in the process of being sent
     */
    MessageStatusPending,
    /**
     *  Message failed to sent to the server
     */
    MessageStatusFailed,
    /**
     *  Message has been sent to the server
     */
    MessageStatusSent,
    /**
     *  Message has been read by the recipient(s)
     */
    MessageStatusRead
};

/**
 *  Enum representing the different states of Acknowledgement
 */
typedef NS_ENUM(NSUInteger, AcknowledgementState){
    /**
     *  No acknowledgement required
     */
    AcknowledgementStateAcknowledgementOff,
    /**
     *  Acknowledgement is required, but not yet acknowledged
     */
    AcknowledgementStateUnAcknowledged,
    /**
     *  Used only for groups, where some people acknoweledged, but not all
     */
    AcknowledgementStatePartiallyAcknowledged,
    /**
     *  The recipient (or ALL recipients in a group) has acknowledged
     */
    AcknowledgementStateAcknowledged
};

/**
 *  Bit-mask for setting various options on new messages. When you have a CNMMessage, the values will be explicit properties
 *
 * Note: You should should not pass in 0, if you don't know what you want, choose CNMMessageOptionsDefault. If you put in 0,
 * we will assume no options and message priority will be Low
 */
typedef NS_OPTIONS(NSUInteger, CNMMessageOptions){
    /**
     *  Most important priority
     */
    CNMMessageOptionsPriorityHigest    = 0,
    /**
     *  High priority
     */
    CNMMessageOptionsPriorityHigh      = 1,
    /**
     *  Medium / normal priority
     */
    CNMMessageOptionsPriorityMedium    = 2,
    /**
     *  Lowest priority message
     */
    CNMMessageOptionsPriorityLow       = 3,
    /**
     * The first 2 bits are priorty bits.
     */
    CNMMessageOptionsPriorityMask      = CNMMessageOptionsPriorityLow,
    /**
     *  Setting this option indicates that a message should not be forwarded
     */
    CNMMessageOptionsForwardRestricted = 1 << 3,
    /**
     *  Setting this option indicates that a message requires a read receipt.
     * Messages with this setting will not provide plain text until message is marked
     * as recieved / read. See markMessageAsAcknowledged for details
     */
    CNMMessageOptionsReadReceipt       = 1 << 4,
    /**
     *  Default
     */
    CNMMessageOptionsDefault           = CNMMessageOptionsPriorityLow,
};