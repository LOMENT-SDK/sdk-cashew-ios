//
//  CNMCryptoServices.h
//  MessagingSDK
//
//  Created on 7/23/15.
//  Copyright (c) 2015 Loment. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Protocol used for encrypting/decrypting string messages. Internally, the SDK has an interface very similar to this protocol.
 * 
 * If you wish to override provided crypto functionality create you would create an object that implements all these methods and provide SDK access
 * to said object
 */
@protocol CNMCryptographer <NSObject>

@required
/**
 *  Encrypts a string. Sender and recipients name can be used to help seed encryption key.
 *
 *  @param plainString The plain text
 *  @param sender      The sender
 *  @param recipient   The recipient
 *
 *  @return Base64'd encrypted string. If value is not base64, unexcpected behavior may arrise
 */
- (NSString *)encryptString:(NSString *)plainString sender:(NSString *)sender recipient:(NSString *)recipient;

/**
 *  Decrypts a string. Sender and recipients name can be used to help seed encryption key.
 *
 *  @param encrpyptedString The encrypted string
 *  @param sender           The sender
 *  @param recipient        The recipient
 *
 *  @return The plain text
 */
- (NSString *)decryptString:(NSString *)encrpyptedString sender:(NSString *)sender recipient:(NSString *)recipient;

/**
 *  Encrypts a string. Sender and group ID can be used to help seed encryption key.
 *
 *  @param plainString The plain text
 *  @param sender      The sender
 *  @param groupId     The group ID
 *
 *  @return Base64'd encrypted string. If value is not base64, unexcpected behavior may arrise
 */
- (NSString *)encryptString:(NSString *)plainString sender:(NSString *)sender groupId:(NSString *)groupId;

/**
 *  Decrypts a string. Sender and group ID can be used to help seed encryption key.
 *
 *  @param encrpyptedString The encrypted string
 *  @param sender           The sender
 *  @param groupId          The group ID
 *
 *  @return The plain text
 */
- (NSString *)decryptString:(NSString *)encrpyptedString sender:(NSString *)sender groupId:(NSString *)groupId;

/**
 *  Encrypts plain data. Sender and recipient can be used to help seed encryption key.
 *
 *  @param plainData The plain data
 *  @param sender    The sender
 *  @param recipient The recipient
 *
 *  @return The encrypted data.
 */
- (NSData *)encryptData:(NSData *)plainData sender:(NSString *)sender recipient:(NSString *)recipient;

/**
 *  Decrypts data. Sender and recipients name can be used to help seed encryption key.
 *
 *  @param encrpyptedData   The encrypted data
 *  @param sender           The sender
 *  @param recipient        The recipient
 *
 *  @return The plain data
 */
- (NSData *)decryptData:(NSData *)encrpyptedData sender:(NSString *)sender recipient:(NSString *)recipient;

/**
 *  Encrypts plain data. Sender and group id can be used to help seed encryption key.
 *
 *  @param plainData The plain data
 *  @param sender    The sender
 *  @param groupId   The recipient
 *
 *  @return The encrypted data.
 */
- (NSData *)encryptData:(NSData *)plainData sender:(NSString *)sender groupId:(NSString *)groupId;

/**
 *  Decrypts data. Sender and group Id can be used to help seed encryption key.
 *
 *  @param encrpyptedData   The encrypted data
 *  @param sender           The sender
 *  @param groupId          The recipient
 *
 *  @return The plain data
 */
- (NSData *)decryptData:(NSData *)encrpyptedData sender:(NSString *)sender groupId:(NSString *)groupId;

@end

/**
 *  The class is in charge of all custom cryptography. 
 *
 *  If you would like to bypass Loment cryptography and use a custom one, create an object that adheres to above protocol. Once you have, set that object
 * to the dataCrypter property on this singleton.
 *
 *  Be sure to call this before calling any other SDK call. IF you don't and SDK needs to encrypt / decrypt it will use SDK encryption by default
 *
 *  Lastly, this class also implements the protocol using default SDK encryption
 */
@interface CNMCryptoServices : NSObject <CNMCryptographer>

/**
 *  The singleton of this object
 *
 *  @return Singleton
 */
+ (instancetype)sharedInstance;

/**
 *  Nil by default. As an SDK user set this property only if you would like to have custom cryptography around encrypting messages
 *
 * As a reminder, this needs to happen before any other call to the SDK. And you cannot change this middle of running SDK or unexpected results may happen
 */
@property (nonatomic, strong) NSObject <CNMCryptographer> * dataCrypter;

@end