//
//  ObjectsCollectionViewItem.m
//  Light Year
//
//  Created by Michael Bethke on 2015-12-02.
//  Copyright © 2015 2Cat Studios. All rights reserved.
//

#import "ObjectsCollectionViewItem.h"
#import "ObjectActionCreator.h"

@interface ObjectsCollectionViewItem ()

@end

@implementation ObjectsCollectionViewItem

- (void)viewDidLoad {
    [super viewDidLoad];

	//[[self primaryButton] setTitle:@""];
}

- (void) viewWillAppear
{

	[self populateObject];
}

- (void) populateObject
{

	ObjectActionCreatorObjectsArrayItem *arrayObject = self.representedObject;

	NSNumberFormatter *nsstringToNSNumber = [[NSNumberFormatter alloc] init];
	nsstringToNSNumber.numberStyle = NSNumberFormatterNoStyle;
	self.itemID = [nsstringToNSNumber numberFromString:arrayObject.itemID];

	self.itemName = arrayObject.itemName;

	NSButton *primaryButton = [self.view viewWithTag:1];
	[primaryButton setTitle:self.itemName];
}

@end
