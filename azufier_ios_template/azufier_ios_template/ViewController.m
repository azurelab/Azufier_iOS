//
//  ViewController.m
//  azufier_ios_template
//
//  Created by Abue on 11/23/15.
//  Copyright (c) 2015 azurelab. All rights reserved.
//

#import "ViewController.h"

//this is default service uuid
#define SERVICE_UUID @"C14D2C0A-401F-B7A9-841F-E2E93B80F631"

@interface ViewController ()
{
    CiGate *Azufier;
    CiGateState _state;
}
@property CiGateState state;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    Azufier =[[CiGate alloc]initWithDelegate:self autoConnectFlag:TRUE
                            serviceUuidStr:SERVICE_UUID];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)iGateDidReceivedData:(NSData *)data
{
    
}

-(void)iGateDidUpdateState:(CiGateState)iGateState
{
    [self setState:iGateState];
    switch(iGateState)
    {
        case CiGateStateConnecting:
            if([Azufier getConnectDevName])
                self.deviceStateLabel.text=[@"Connecting " stringByAppendingString:[Azufier getConnectDevName]];
            break;
        case CiGateStateConnected:
            if([Azufier getConnectDevName])
                self.deviceStateLabel.text=[@"Connected " stringByAppendingString:[Azufier getConnectDevName]];
            break;
        case CiGateStateBonded:
            if([Azufier getConnectDevName])
                self.deviceStateLabel.text=[@"Linked " stringByAppendingString:[Azufier getConnectDevName]];
            break;
    }
    NSLog(@"Azufier: %@, State: %@",Azufier,self.deviceStateLabel.text);
}

@end
