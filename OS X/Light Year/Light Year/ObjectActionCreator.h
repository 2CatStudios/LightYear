//
//  ObjectActionCreator.h
//  Light Year
//
//  Created by Michael Bethke on 2015-12-02.
//  Copyright © 2015 2Cat Studios. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ObjectActionCreator : NSViewController

@property (strong) IBOutlet NSCollectionView *objectsCollectionView;
@property (strong) IBOutlet NSTextField *objectsCollectionViewCountAndTitle;
@property (strong) IBOutlet NSArrayController *objectsCollectionViewArray;

@property (strong, nonatomic) NSMutableArray *objects;

- (void) createNewObjectWithTitle:(NSString *)objectName andUUID:(NSNumber *)objectUUID;

@end


@interface lightyearObject : NSObject

/*! Unique numerical identification.*/
@property (nonatomic, strong) NSNumber *objectID;
/*! An object's identifier for use in human-readable cases. This does not have to be unique.*/
@property (nonatomic, strong) NSString *objectName;

@property (nonatomic, strong) NSString *shortDescription;
@property (nonatomic, strong) NSString *longDescription;

@property (nonatomic) BOOL storable;
@property (nonatomic, strong) NSNumber *objectWeight;

@property (nonatomic) BOOL equipable;

@property (nonatomic) BOOL usable;

@end