//
//  helloworldViewController.m
//  helloworld
//
//  Created by Jared De La Cruz on 9/22/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "helloworldViewController.h"

@implementation helloworldViewController

//synthesize the property
@synthesize txtName;

-(IBAction) btnClicked:(id) sender
{
	NSString *temp = [self tree];
	NSString *str = [[NSString alloc] initWithFormat:@"%@", temp];
	//Display an alert view
	UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Reverse Triangle" message:str delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
	[alert show]; 
	[str release];
	[alert release];
}


- (NSString *)tree
{
	NSString *tree = txtName.text;
	NSString *temp;
	int num =  [tree floatValue];
		
	for (int i = 0; i<=num; i++)
	{
		for (int j = 0; j<i; j++) 
		{
			temp = [NSString stringWithFormat:@"%i", j];
			[tree appendString: temp];
		}
		temp = [NSString stringWithFormat:@"\n"];
		[tree appendString: temp];
	}
	
	temp = [tree substringFromIndex:2];
	return temp;
}
/*
// The designated initializer. Override to perform setup that is required before the view is loaded.
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}
*/

/*
// Implement loadView to create a view hierarchy programmatically, without using a nib.
- (void)loadView {
}
*/


/*
// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad {
    [super viewDidLoad];
}
*/


// Override to allow orientations other than the default portrait orientation.
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    return YES;
}

- (void)didReceiveMemoryWarning {
	// Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
	
	// Release any cached data, images, etc that aren't in use.
}

- (void)viewDidUnload {
	// Release any retained subviews of the main view.
	// e.g. self.myOutlet = nil;
}

- (void)dealloc {
	//release the outlet
	[txtName release];
    [super dealloc];
}

@end
