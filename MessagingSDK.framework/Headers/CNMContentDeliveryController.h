//
//  CNMContentDeliveryController.h
//  MessagingSDK
//
//  Created on 8/17/15.
//  Copyright (c) 2015 Loment. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CNMContentDeliveryController;

/**
 *  NSFetchedResultsChangeType like change type enum for when content changes
 */
typedef NS_ENUM(NSUInteger, CNMFetchResultsChangeType){
    /**
     *  Data is inserted
     */
    CNMFetchResultsChangeInsert = 1,
    /**
     *  Date has been deleted
     */
    CNMFetchResultsChangeDelete = 2,
    /**
     *  Data has moved
     */
    CNMFetchResultsChangeMove   = 3,
    /**
     *  Data is simply updated
     */
    CNMFetchResultsChangeUpdate = 4
};

/**
 *  NSFetchedResultsControllerDelegate like delegate method collection for when the CNMContentDeliveryController updates
 */
@protocol CNMContentDeliveryControllerDelegate

@required
/**
 *  The controller is about to change content
 *
 *  @param controller The controller in question
 */
- (void)controllerWillChangeContent:(CNMContentDeliveryController *)controller;

/**
 *  Invidual calls for object CRUT
 *
 *  @param controller   The controller in queustion
 *  @param anObject     The CNMObject that is being updated
 *  @param indexPath    The index path of the object
 *  @param type         The type of change
 *  @param newIndexPath The new indexpath
 */
- (void)controller:(CNMContentDeliveryController *)controller didChangeObject:(id)anObject atIndexPath:(NSIndexPath *)indexPath forChangeType:(CNMFetchResultsChangeType)type newIndexPath:(NSIndexPath *)newIndexPath;
/**
 *  The controller did change content
 *
 *  @param controller The controller in question
 */
- (void)controllerDidChangeContent:(CNMContentDeliveryController *)controller;

@end

/**
 *  This delivers CNMObjects in an FRC like fashion for quick access. Example usages are for a list of conversations, or viewing a list of messages
 * in a conversation.
 *
 * How to use this class. When you obtain a CNMContentDeliveryController, first set yourself as the delegate. Then call `fetchData` and lastly
 * since you are backing the view by a tableview call `reloadData` on the tableView.
 *
 * It is important to clean up properly, so when you stop messaging services, get an interuption, or leave the screen that has a reference to a 
 * CNMContentDeliveryController, it is imporant to let of that strong reference and recreate it as needed. If not data would most likely become stale
 * or other unexpected behavior may happen.
 */
@interface CNMContentDeliveryController : NSObject

/**
 *  Once you have a CNMContentDeliveryController you must call this method to begin listening to changes.
 *
 * NOTE: If your tableview is already loaded, you must call reloaddata on your tableview after calling this method. Just like a normal FRC
 *
 *  @param error Error reference
 *  @return YES / NO on pass / fail
 */
- (BOOL)fetchData:(NSError * __autoreleasing *)error;

/**
 *  Number of objects backed by this content delivery
 *
 *  @return Count of objects
 */
- (NSUInteger)numberOfObjects;

/**
 *  All the fetched objects
 *
 *  @return All the objects
 */
- (NSArray *)allObjects;

/**
 *  Retrieves the CNMObject at given indexPath
 *
 *  @param indexPath The indexPath to retrieve from
 *
 *  @return The CNMObject
 */
- (id)objectAtIndexPath:(NSIndexPath *)indexPath;

/**
 *  Delegate to update on.
 */
@property(nonatomic, assign) NSObject <CNMContentDeliveryControllerDelegate> * delegate;

@end