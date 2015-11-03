//
//  MainView.h
//  Light-Year
//
//  Created by Michael Bethke on 2015-10-09.
//  Copyright © 2015 2Cat Studios. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "UpdateString.h"
#import "ReceiveInput.h"


@interface MainView : NSView

@property (strong) IBOutlet NSTextField *labelBuildVersion;

@property (strong) IBOutlet NSScrollView *labelMainScroll;
@property (strong) IBOutlet NSTextView *labelMainText;
@property (strong) IBOutlet NSTextField *textFieldInput;
- (IBAction)textFieldInputAction:(id)sender;


@end
