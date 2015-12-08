//
//  ObjectActionCreator.m
//  Light Year
//
//  Created by Michael Bethke on 2015-12-02.
//  Copyright © 2015 2Cat Studios. All rights reserved.
//

#import "ObjectActionCreator.h"

@implementation ObjectActionCreatorObjectsArrayItem
@end

@implementation ObjectActionCreator

- (void)viewDidLoad {
    [super viewDidLoad];

	NSCollectionViewItem *objectsCollectionViewItem = [self.storyboard instantiateControllerWithIdentifier:@"ObjectsCollectionViewItem"];
	[self.objectsCollectionView setItemPrototype:objectsCollectionViewItem];

	[self publishNewObjectButton:nil];
}

- (IBAction)publishNewObjectButton:(id)sender
{

	[self createNewObjectWithTitle:@"Create Object" andUUID:0];
}

- (void) createNewObjectWithTitle:(NSString *)objectName andUUID:(NSNumber *)objectUUID
{

	ObjectActionCreatorObjectsArrayItem *newTestingObject = [[ObjectActionCreatorObjectsArrayItem alloc] init];
	[newTestingObject setItemName:[NSString stringWithFormat:@"New Object %@", [NSNumber numberWithLong:[self objectsCollectionViewObjectsArrayCount] + 1]]];
	[newTestingObject setItemID:@"001"];

	[[self objectsCollectionViewObjectsArray] addObject:newTestingObject];
	[self updateObjectsCollectionViewCount];
}

- (void)updateObjectsCollectionViewCount {

	NSNumber *arrayCount = [NSNumber numberWithLong:[self objectsCollectionViewObjectsArrayCount]];
	NSString *correctObjectString = @"Objects";

	if ([arrayCount integerValue] == [[NSNumber numberWithInt:1] integerValue])
	{

		correctObjectString = [correctObjectString substringToIndex:[correctObjectString length] - 1];
	}

	[[self objectsCollectionViewCountAndTitle] setStringValue:[NSString stringWithFormat:@"%@ %@", arrayCount, correctObjectString]];
}

-(NSUInteger) objectsCollectionViewObjectsArrayCount
{

	return [[[self objectsCollectionViewObjectsArray] arrangedObjects] count];
}

@end
