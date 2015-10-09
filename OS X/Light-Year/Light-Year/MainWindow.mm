//
//  MainWindow.m
//  Light-Year
//
//  Created by Michael Bethke on 2015-10-09.
//  Copyright © 2015 2Cat Studios. All rights reserved.
//

#import "MainWindow.h"

@implementation MainWindow

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
}


int changeCenterLabelInterface (void *self, void *newText)
{

	return [(id) self changeCenterLabel(newText)];
}

- (void) changeCenterLabelTo:(void *) newText
{

	NSString *newLabelValue = newText;

	[self.centerLabel setStringValue:newLabelValue];
	return 0;
}

@end
