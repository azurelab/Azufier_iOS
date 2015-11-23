//
//  ViewController.h
//  azufier_ios_template
//
//  Created by Abue on 11/23/15.
//  Copyright (c) 2015 azurelab. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "iGate.h"

@interface ViewController : UIViewController<CiGateDelegate>

@property (weak, nonatomic) IBOutlet UILabel *deviceStateLabel;

@end

