//
//  CNMUserServices.h
//  CNMUserServicesSDK
//
//  Created on 21/07/2015.
//  Copyright (c) 2015 Loment. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CNMUser;

/**
 *  Completion block that is common to all webservices calls. Returns either a valid
 * CNMUser object on success to an error in situations where something went wrong. Only one or the other should be returned.
 *
 * After registering / authenticating many of the other calls require a CNMUser as input, use the object returned here.
 *
 *  @param user  The CNMUser object representing a Loment account, with the latest known data
 *  @param error An error if present
 */
typedef void (^CNMUserServicesCompletion)(CNMUser * user, NSError *error);

/**
 *  This class provides all the necessary methods required to work with a Loment account. It includes methods to register & authenticate
 * as well as methods to initiate password recovery, verify current subscription and lastly add Cashew messaging accounts to the Loment
 * account.
 *
 * Special note on authenticate, it will automatically verify your subscription, so error messages indicating invalid subscription may be returned here.
 *
 * The two major workflows are either Register-Login or Login. It is up to users of the SDK to create a seamless user interaction to achieve registration / login.
 *
 * Lastly, in order to properly use the messaging SDK, the SDK must be provided with a CMNCashewAccount, this can only be obtained after validating login of the Loment
 * account. Once you receive a valid CNMUser from login, use the desired CNMCashewAccount with the CNMMessagingServices interface to begin using the messaging framework.
 */
@interface CNMUserServices : NSObject

/**
 *  In order to properly use the SDK, one must register with SDK by call this method. The method is a prereq to all other methods in the SDK
 *
 *  @param clientId    Your client Id
 *  @param partnerId   Your partner Id
 *
 *  @return YES if it succeeds, NO if not. Ensure all your provided data is correct
 */
+ (BOOL)registerWithSDK:(NSString *)clientId partnerId:(NSString *)partnerId;

/**
 *  Register a new user. To must excplictly call login after. See class description for more details.
 *
 *  @param name        This is the user's name (i.e. John Smith)
 *  @param password    User's password
 *  @param email       User's email. This will be their Loment ID
 *  @param phone       User's phone number. Must be prefixed with correct country code
 *  @param isoCode     iso code for country of phone number provided
 *  @param completion  Completion block executed when the network block completes
 */
+ (void)registerUserWithName:(NSString *)name
                withPassword:(NSString *)password
                   withEmail:(NSString *)email
                   withPhone:(NSString *)phone
                 withIsoCode:(NSString *)isoCode
              withCompletion:(CNMUserServicesCompletion)completion;

/**
 *  Authenticate user to start communicating with the server.
 *
 * Completion block returns CNMUser on success. After login success, allow user to pick desired CNMCashewAccount from list of available accounts, 
 * pass that selected account to MessagingServices to begin Loment Messaging.
 *
 * See CNMUserServicesCompletion for more details
 *
 *  @param email      User's email
 *  @param password   User's password
 *  @param completion Completion block executed when the network block completes
 */
+ (void)authenticateUser:(NSString *)email withPassword:(NSString *)password withCompletion:(CNMUserServicesCompletion)completion;

/**
 *  Sends recover password email to the specified email address
 *
 *  @param email      Email address to the recover password email to
 *  @param completion Completion block excuted when the network block completes (CNMUser will not be set)
 */
+ (void)recoverPasswordForEmail:(NSString *)email withCompletion:(CNMUserServicesCompletion)completion;

/**
 *  Sends Changepassword password email to the specified email address
 *
 *  @param email        Email address to the change password for email to
 *  @param newpassword  New password to be set for the account.
 *  @param completion   Completion block excuted when the network block completes (CNMUser will not be set)
 */
+ (void)changepasswordForEmail:(NSString *)email withNewPassword:(NSString *)newpassword withCompletion:(CNMUserServicesCompletion)completion;
/**
 *  Sends Changepassword password email to the specified email address
 *
 *  @param email            Email address to the change password for email to
 *  @param currentpassword  current password for the account
 *  @param newpassword      New password to be set for the account.
 *  @param completion       Completion block excuted when the network block completes (CNMUser will not be set)
 */

+ (void)changepasswordForEmail:(NSString *)email withCurrentPassword:(NSString *)currentpassword andNewPassword:(NSString *)newpassword withCompletion:(CNMUserServicesCompletion)completion;

/**
 *  Creates the Cashew Username for the specified user
 *
 *  @param cashewUsername   New Cashew Username
 *  @param user             User for which the ID will be associated with
 *  @param completion       Completion block executed when the network block completes
 */
+ (void)addCashewAccount:(NSString *)cashewUsername forUser:(CNMUser *)user withCompletion:(CNMUserServicesCompletion)completion;

/**
 *  Verify the given Loment account represented by CNMUser
 *
 *  @param user       User account object to validate
 *  @param completion Completion block executed when the network block completes
 */
+ (void)verifySubscriptionForUser:(CNMUser *)user withCompletion:(CNMUserServicesCompletion)completion;

@end
