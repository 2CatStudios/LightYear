//
//  MainMenu.m
//  Light Year
//
//  Created by Michael Bethke on 2015-12-30.
//  Copyright © 2015 2Cat Studios. All rights reserved.
//

#import "MainMenu.h"

@implementation MainMenu

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];


	NSDictionary *info = [[NSBundle mainBundle] infoDictionary];
	NSString *clientVersion = [info objectForKey:@"CFBundleShortVersionString"];

	NSString *engineVersion = @"GET BUILD VERSION"; //engineBuildVersion;

	[[self versionText] setStringValue:[NSString stringWithFormat:@"%@, %@", clientVersion, engineVersion]];
}

- (IBAction)websiteButton:(id)sender {

	NSWorkspace * workspace = [NSWorkspace sharedWorkspace];
	[workspace openURL:[NSURL URLWithString:@"http://2catstudios.github.io/main.html"]];
}
@end
