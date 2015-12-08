//
//  ObjectsCollectionViewItem.m
//  Light Year
//
//  Created by Michael Bethke on 2015-12-02.
//  Copyright © 2015 2Cat Studios. All rights reserved.
//

#import "ObjectsCollectionViewItem.h"

@interface ObjectsCollectionViewItem ()

@end

@implementation ObjectsCollectionViewItem

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do view setup here.

	[[self primaryButton] setTitle:[NSString stringWithFormat:@"%@", [NSNumber numberWithLong:random()]]];
}

@end
