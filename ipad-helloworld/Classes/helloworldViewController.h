//
//  helloworldViewController.h
//  helloworld
//
//  Created by Jared De La Cruz on 9/22/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface helloworldViewController : UIViewController {
	//declaring the outlet
	IBOutlet UITextField *txtName;

}
//expose outlet as property
@property (nonatomic, retain) UITextField *txtName;
//delcaring the action
-(IBAction) btnClicked:(id) sender;

-(NSString*)tree;

@end

