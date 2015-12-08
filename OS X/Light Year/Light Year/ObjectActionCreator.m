//
//  ObjectActionCreator.m
//  Light Year
//
//  Created by Michael Bethke on 2015-12-02.
//  Copyright © 2015 2Cat Studios. All rights reserved.
//

#import "ObjectActionCreator.h"

/*@interface ObjectActionCreator ()

@end*/

@implementation ObjectActionCreatorObjectsArrayItem
@end

@implementation ObjectActionCreator

- (void)viewDidLoad {
    [super viewDidLoad];

	NSCollectionViewItem *objectsCollectionViewItem = [self.storyboard instantiateControllerWithIdentifier:@"ObjectsCollectionViewItem"];
	[self.objectsCollectionView setItemPrototype:objectsCollectionViewItem];

	//[self publishNewObjectButton:nil];
}

- (IBAction)publishNewObjectButton:(id)sender
{

	ObjectActionCreatorObjectsArrayItem *newTestingObject = [[ObjectActionCreatorObjectsArrayItem alloc] init];
	[newTestingObject setItemName:@"Testing Object"];
	[newTestingObject setItemID:@"001"];

	[[self objectsCollectionViewObjectsArray] addObject:newTestingObject];
	NSLog (@"Test Object Added");

	[self updateObjectsCollectionViewCount];
}

- (void)updateObjectsCollectionViewCount {

	[[self objectsCollectionViewCountAndTitle] setStringValue:[NSString stringWithFormat:@"%ld Objects", [[[self objectsCollectionViewObjectsArray] arrangedObjects] count]]];
}
@end
