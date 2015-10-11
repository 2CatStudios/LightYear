//
//  UpdateStringLiaison.m
//  Light-Year
//
//  Created by Michael Bethke on 2015-10-10.
//  Copyright © 2015 2Cat Studios. All rights reserved.
//

#import "UpdateStringLiaison.h"

@implementation UpdateStringLiaison

+ (NSString *) getNewString
{

	return [NSString stringWithUTF8String:newStringFromInput([[NSString stringWithFormat:@"%d", rand()] UTF8String])];
}

@end
