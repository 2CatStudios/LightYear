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
@property (strong) IBOutlet NSArrayController *objectsCollectionViewObjectsArray;

@end


@interface ObjectActionCreatorObjectsArrayItem : NSObject

@property (nonatomic, strong) NSString *itemName;
@property (nonatomic, strong) NSString *itemID;

@end