# Azufier-iOS-SDK

This is an iOS SDK document for [Azufier](http://www.azure-lab.com).

Azufier is an BLE chip onboard with Atmega32u4 microcontroller. See [www.azure-lab.com](http://www.azure-lab.com) for more details

###Content
1. azufier_ios_template
 - This is a template of Azufier for those who want to create more awesome project. It helps you know the SDK more quicker!
2. SDK
 - Files that needed when using SDK

###Template Usage
1. Download this respo and open azufier_ios_template.xcodeproj
2. Plug your iPhone to Mac and Run.(Note that the iPhone's OS version must be iOS7.0 or above)
3. Power up Azufier and the app will **auto-connect** Azufier itself.

###SDK Setup Steps
1. Copy all files in SDK folder to your project.
2. Make sure "libiGate.a" andd "CoreBluetooth.framework" are imported at "Linked Frameworks or Libraries" option
3. Import iGate.h and add delegate method to yourcontroller.h Example is shown below
 ```h
....
#import "iGate.h"

@interface ViewController : UIViewController<CiGateDelegate>
...
````

4. Init Azufier instance as below.See more at [Documentation](http://www.azure-lab.com/documentation/interface_ci_gate.html).
 ```m
....
CiGate Azufier =[[CiGate alloc]initWithDelegate:self autoConnectFlag:TRUE
                            serviceUuidStr:SERVICE_UUID];
...
````
5. Add two required method, And you are received data from iOS Device :)
```m
...
-(void)iGateDidReceivedData:(NSData *)data{}
-(void)iGateDidUpdateState:(CiGateState)iGateState{}
...
````

###Documentation
See more SDK details at [here](http://www.azure-lab.com/documentation/index.html)

###Reference
1. [Azufier-Hardware](https://github.com/azurelab/Azufier-Hardware)
2. [Azufier-iOS-SDK](https://github.com/azurelab/Azufier_iOS)
3. [Azufier-Library](https://github.com/azurelab/Azufier-Library)
