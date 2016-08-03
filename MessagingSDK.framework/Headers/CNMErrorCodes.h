//
//  CNMErrorCodes.h
//  MessagingSDK
//
//  Created on 7/27/15.
//  Copyright (c) 2015 Loment. All rights reserved.
//

/**
 *  Foundational Error codes to be used through the entire SDK
 */
typedef NS_ENUM(NSUInteger, SDKFoundationError)
{
    /**
     *  Error indicating that the developer has not registered SDK yet
     */
    SDKFoundationErrorDidNotRegister                     = -1000,
    /**
     *  Error indicating SDK user is missing parameters in method call. Check user info for details
     */
    SDKFoundationErrorMissingParameters                  = -1001,
    /**
     *  Error indicating there was a problem when saving to the database
     */
    SDKFoundationErrorSavingToDatabase                   = -1002,
    /**
     *  An error indicating that the SDK is already running messagine service
     */
    SDKFoundationErrorMessagingServiceAlreadyRunning     = -1003,
    /**
     *  An error indicating that the SDK is not running messagine service
     */
    SDKFoundationErrorMessagingServiceNotRunning         = -1004,
    /**
     *  An error indicating that the SDK could not start messaging service
     */
    SDKFoundationErrorMessagingServiceFailedToStart      = -1005,
    /**
     *  An error indicating that the SDK could send message to server
     */
    SDKFoundationErrorMessagingServiceFailedToSend       = -1006,
    /**
     *  Cannot switch accounts after successful login
     */
    SDKFoundationErrorCannotSwitchAccounts               = -1007,
    /**
     *  Error if attachment is already being downloaded
     */
    SDKFoundationErrorAlreadyDownloadingAttachment       = -1008

};

/**
 *  Error codes specific to networking layer
 */
typedef NS_ENUM(NSUInteger, SDKNetworkError) {

    // ============
    // Common codes
    // ============

    /**
     *  During an SDK network call, we encountered an error. If you receive an error with this code, check the underlying error
     */
    SDKNetworkErrorCheckNSFoundation                             = -1000,
    /**
     *  Unknown / unhandled exception. We will attempt to gain as much information as we can and put it in the userinfo
     */
    SDKNetworkErrorUnkown                                        = -1001,
    /**
     *  Server returned Generic Failure
     */
    SDKNetworkErrorGenericFailure                                = 1,
    /**
     *  No user account was found on server
     */
    SDKNetworkErrorUserAccountNotFound                           = 10002,
    /**
     *  The user account is inactive
     */
    SDKNetworkErrorUserAccountInactive                           = 10003,
    /**
     *  The device specified is not found
     */
    SDKNetworkErrorDeviceNotFound                                = 20002,
    /**
     *  The device specified is inactive
     */
    SDKNetworkErrorDeviceInactive                                = 20003,
    /**
     *  The account is not found
     */
    SDKNetworkErrorAccountNotFound                               = 30002,
    /**
     *  The account is inactive
     */
    SDKNetworkErrorAccountInactive                               = 30003,
    /**
     *  The client application is out of date and must be upgraded
     */
    SDKNetworkErrorClientApplicationMustBeUpgraded               = 99999,

    // ============
    // User Registration
    // ============

    /**
     *  Duplicate username encountered during signup
     */
    SDKNetworkErrorDuplicateUsername                             = 10102,
    /**
     *  Duplicate mobile number encountered during signup
     */
    SDKNetworkErrorDuplicateMobileNumber                         = 10103,
    /**
     *  Invalid data when attempting to sign up
     */
    SDKNetworkErrorInvalidData                                   = 10104,
    /**
     *  Another account is using provided mobile number
     */
    SDKNetworkErrorOtherAccountUsingMobileNumber                 = 10105,

    // ============
    // User Authentication
    // ============

    /**
     *  Invalid username when authenticating
     */
    SDKNetworkErrorInvalidUsername                               = 10202,
    /**
     *  Invalid password when authenticating
     */
    SDKNetworkErrorInvalidPassword                               = 10203,
    /**
     *  Account is inactive
     */
    SDKNetworkErrorUserAuthAccountInactive                       = 10204,

    // ============
    // User Profile Update
    // ============

    /**
     *  Invalid data when attempting to update profile
     */
    SDKNetworkErrorUpdateProfileInvalidData                      = 10304,

    // ============
    // Add User Device
    // ============

    /**
     *  Duplicate device id encountered when adding device
     */
    SDKNetworkErrorDuplicateDeviceId                             = 20102,
    /**
     *  Duplicate device name encountered when adding device
     */
    SDKNetworkErrorDuplicateDeviceName                           = 20103,
    /**
     *  Unknown server error when trying to add device
     */
    SDKNetworkErrorAddDeviceTypeNotKnown                         = 20105,
    /**
     *  Device id is not valid
     */
    SDKNetworkErrorDeviceIdNotValid                              = 20205,

    // ============
    // Update User Device
    // ============

    /**
     *  Duplicate device id encountered when updating device
     */
    SDKNetworkErrorUpdateDeviceDuplicateDeviceId                 = 20202,
    /**
     *  Duplicate device name encountered when updating device
     */
    SDKNetworkErrorUpdateDeviceDuplicateDeviceName               = 20203,
    /**
     *  Unknown server error when trying to update device
     */
    SDKNetworkErrorUpdateDeviceTypeNotKnown                      = 20204,
    /**
     *  Device id is not valid
     */
    SDKNetworkErrorUpdateDeviceDeviceIdInvalid                   = 20205,
    /**
     *  Device does not have a valid status
     */
    SDKNetworkErrorInvalidDeviceStatus                           = 20206,

    // ============
    // Add Account or Add User Account to Device
    // ============

    /**
     *  Duplicate account name when performing operations
     */
    SDKNetworkErrorAccountNameDuplicate                          = 30202,
    /**
     *  Account provider is not known
     */
    SDKNetworkErrorAccountProviderNotKown                        = 30203,
    /**
     *  Server protocol is not known
     */
    SDKNetworkErrorAccountServerProtocolNotKnown                 = 30204,
    /**
     *  Server SSL settings not valid
     */
    SDKNetworkErrorAccountServerSSLEnabledDisabledSettingInvalid = 30205,
    /**
     *  Server port setting is incorrect
     */
    SDKNetworkErrorAccountServerPortSettingInvalid               = 30206,
    /**
     *  Account status is not valid
     */
    SDKNetworkErrorAccountStatusInvalid                          = 30207,
    /**
     *  Duplicate account name when performing operations
     */
    SDKNetworkErrorUserAccountNameDuplicate                      = 30102,
    /**
     *  Duplicate account name when performing operations
     */
    SDKNetworkErrorAddUserAccountNameDuplicate                   = 30103,

    // ============
    // User Account Recovery
    // ============

    /**
     *  Invalid key
     */
    SDKNetworkErrorInvalidKey                                    = 10402,
    /**
     *  Expired key
     */
    SDKNetworkErrorExpiredKey                                    = 10403,

    // ============
    // Payment and Subscription
    // ============

    /**
     *  Needs documentation
     */
    SDKNetworkErrorGivenPaymentGatewayIdIsNotAvailable           = 40102,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorGivenPaymentGatewayIsNotActive                = 40103,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorInvalidSubscriptionStartDate                  = 40104,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorInvalidSubscriptionEndDate                    = 40105,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorInvalidAmount                                 = 40106,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorInvalidSubscripedFeatures                     = 40107,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorGivenPaymentIdNotFound                        = 40111,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorGivenPaymentStatusIsInvalid                   = 40109,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorGivenLogDirectionIsInvalid                    = 40110,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorGivenBillIdNotFound                           = 40111,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorGivenRenewalBillIdNotFound                    = 40112,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorGivenBillStatusIsInvalid                      = 40113,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorGivenSubscriptionEndDateForBillIsInvalid      = 40114,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorGivenPaymentIdAlreadyHasABillAttachedToIt     = 40115,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorGivenBillKeyIsInvalid                         = 40116,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorPaymentFailedAtPaymentGateway                 = 40117,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorGivenSubscriptionIdNotFound                   = 50202,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorGivenProductFeatureIdIsInvalid                = 50203,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorGivenDeviceCountInvalid                       = 50205,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorStatusIsInvalid                               = 50205,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorGivenDeviceStatusIsInvalid                    = 50206,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorGivenQuotaExceededForGivenBillOrSubscription  = 50207,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorGivenDeviceAlreadyHasAnActiveSubscription     = 50208,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorNoSubscriptionOrActiveSubscriptionFound       = 50210,
    /**
     *  Needs documentation
     */
    SDKNetworkErrorGivenPrimaryUsernameNotFoundOrInactive        = 50211
};