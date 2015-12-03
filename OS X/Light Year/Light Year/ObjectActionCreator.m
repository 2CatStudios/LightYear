//
//  ObjectActionCreator.m
//  Light Year
//
//  Created by Michael Bethke on 2015-12-02.
//  Copyright © 2015 2Cat Studios. All rights reserved.
//

#import "ObjectActionCreator.h"

@interface ObjectActionCreator ()

@end

@implementation ObjectActionCreator

- (void)viewDidLoad {
    [super viewDidLoad];

	NSCollectionViewItem *objectsCollectionViewItem = [self.storyboard instantiateControllerWithIdentifier:@"ObjectsCollectionViewItem"];
	[self.objectsCollectionView setItemPrototype:objectsCollectionViewItem];

	ObjectActionCreatorObjectsArrayItem *newTestingObject;
	[newTestingObject setItemName:@"Testing Object"];
	[newTestingObject setItemID:@"001"];

	[[self objectsCollectionViewItemsArray] addObject:newTestingObject];

	NSLog (@"Test Object Added");
}

@end
