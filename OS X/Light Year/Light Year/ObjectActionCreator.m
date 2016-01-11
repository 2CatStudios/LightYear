//
//  ObjectActionCreator.m
//  Light Year
//
//  Created by Michael Bethke on 2015-12-02.
//  Copyright © 2015 2Cat Studios. All rights reserved.
//

#import "ObjectActionCreator.h"

@implementation lightyearObject
@end

@implementation ObjectActionCreator

- (void)viewDidLoad {
    [super viewDidLoad];

	self.createdObjects = [NSMutableArray array];
	[self createNewObjectWithTitle:@"New Object" andUUID:0];
}


- (IBAction)publishActionButton:(id)sender {

	[self createNewObjectWithTitle:@"Create Object" andUUID:nil];
}


- (void) createNewObjectWithTitle:(NSString *)newTitle andUUID:(NSNumber *)newUUID
{

	lightyearObject *newObject = [[lightyearObject alloc] init];

	NSNumber *newObjectUUID = newUUID;
	if (!newObjectUUID /*|| UUID Exists */)
	{

		newObjectUUID = [NSNumber numberWithInteger:[self objectsArrayCount]+1];
	}
	[newObject setObjectID:newUUID];

	NSString *newObjectTitle = newTitle;
	if (!newObjectTitle)
	{

		newObjectTitle = [NSString stringWithFormat:@"Object %@", newUUID];
	}
	[newObject setObjectName:newTitle];

	[[self createdObjects] addObject:newObject];
	[self updateObjectsCollectionViewCount];
}


- (void)updateObjectsCollectionViewCount {

	NSNumber *arrayCount = [NSNumber numberWithLong:[self objectsArrayCount]];

	NSString *correctObjectString = @"Objects";
	if ([arrayCount integerValue] == [[NSNumber numberWithInt:1] integerValue])
	{

		correctObjectString = [correctObjectString substringToIndex:[correctObjectString length] - 1];
	}

	[[self objectsCollectionViewCountAndTitle] setStringValue:[NSString stringWithFormat:@"%@ %@", arrayCount, correctObjectString]];
}


-(NSUInteger) objectsArrayCount
{

	return [[self createdObjects] count];
}

@end
