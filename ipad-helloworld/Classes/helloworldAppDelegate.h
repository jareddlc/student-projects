//
//  helloworldAppDelegate.h
//  helloworld
//
//  Created by Jared De La Cruz on 9/22/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@class helloworldViewController;

@interface helloworldAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    helloworldViewController *viewController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet helloworldViewController *viewController;

@end

