//
//  MainWindow.h
//  Light-Year
//
//  Created by Michael Bethke on 2015-10-09.
//  Copyright © 2015 2Cat Studios. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface MainWindow : NSView
{

	int someVar;
}

@property (strong) IBOutlet NSTextField *centerLabel;

- (int) changeCenterLabelTo:(void *)newText;

@end
