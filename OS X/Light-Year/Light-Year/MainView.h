//
//  MainView.h
//  Light-Year
//
//  Created by Michael Bethke on 2015-10-09.
//  Copyright © 2015 2Cat Studios. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "UpdateString.h"


@interface MainView : NSView

@property (strong) IBOutlet NSTextField *labelBuildVersion;
- (IBAction)buttonBuildVersion:(id)sender;

@end
