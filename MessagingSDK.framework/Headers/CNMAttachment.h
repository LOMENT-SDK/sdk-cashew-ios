//
//  CNMAttachment.h
//  MessagingSDK
//
//  Created on 9/14/15.
//  Copyright (c) 2015 Loment. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CNMMessage;

/**
 *  Object representing a message with an attachment. Filename is the name of the original file provided by sender, and should
 * be an indicator what type of file it is.
 */
@interface CNMAttachment : NSObject

/**
 *  The name of the file including extension
 */
@property (nullable, nonatomic, strong, readonly) NSString * filename;

/**
 *  The raw data of the file. Though on disk the data is encrypted, calling this property gives you the non-encrypted form.
 * If data is not yet downloaded this will return nil and you should call the asynchronous version.
 */
@property (nullable, nonatomic, strong, readonly) NSData * data;

/**
 *  The message to which the attachment belongs to
 */
@property (nullable, nonatomic, weak, readonly) CNMMessage * message;

@end