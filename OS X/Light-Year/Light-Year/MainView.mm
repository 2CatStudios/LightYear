//
//  MainView.m
//  Light-Year
//
//  Created by Michael Bethke on 2015-10-09.
//  Copyright © 2015 2Cat Studios. All rights reserved.
//

#import "MainView.h"

@implementation MainView

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];

	[[self labelBuildVersion] setStringValue:[NSString stringWithFormat:@"Build %@", [NSString stringWithUTF8String:buildVersion()]]];
}

@end
