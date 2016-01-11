//
//  MainMenu.h
//  Light Year
//
//  Created by Michael Bethke on 2015-12-30.
//  Copyright © 2015 2Cat Studios. All rights reserved.
//

#import <Cocoa/Cocoa.h>
//#import "MainView.h"

@interface MainMenu : NSView
@property (strong) IBOutlet NSTextField *versionText;
- (IBAction)websiteButton:(id)sender;

@end
