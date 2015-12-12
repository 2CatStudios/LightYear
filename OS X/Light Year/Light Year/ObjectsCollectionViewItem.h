//
//  ObjectsCollectionViewItem.h
//  Light Year
//
//  Created by Michael Bethke on 2015-12-02.
//  Copyright © 2015 2Cat Studios. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ObjectsCollectionViewItem : NSCollectionViewItem

@property (nonatomic, strong) NSNumber *itemID;
@property (nonatomic, strong) NSString *itemName;

@property (strong) IBOutlet NSButton *primaryButton;

@end
