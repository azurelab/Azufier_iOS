//
//  iGate.h
//  iGate
//
//  Created by Zhan on 12-6-18.
//  Copyright (c) 2012年 Novacomm. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CiGateDelegate.h"


@interface CiGate : NSObject<CiGateDelegate>

/*!
 *  @property delegate
 *
 *  @discussion The delegate object you want to receive iGate events.
 *
 */
@property(assign, nonatomic) id<CiGateDelegate> delegate;

/*!
 *  @property state
 *
 *  @discussion The current state of the iGate.
 *      Initially set to CiGateInit.
 *		It can be updated at any moment, upon which the relevant delegate callback will be invoked.
 *      Handle the state changes in iGateDidUpdateState.
 *
 */
@property(readonly) CiGateState state;

/*!
 *  @method initWithDelegate:queue:
 *
 *  @param delegate	The delegate to receive the iGate events such as state changes, received data indications.
 *  @param aFlag set TRUE to automatically connect to the founded device, currently please
                 always set it TRUE.
 *  @discussion The initialization call of iGate.
 *
 */
- (CiGate *)initWithDelegate:(id<CiGateDelegate>)aDelegate autoConnectFlag:(BOOL)aFlag serviceUuidStr:(NSString*)uuidStr;

/*!
 *  @method initWithDelegate:queue:
 *
 *  @param delegate	The delegate to receive the iGate events such as state changes, received data indications.
 *  @param aFlag set TRUE to automatically connect to the founded device, currently please
 always set it TRUE.
 *  @param bondDevUUID The bonded device UUID. When iGate is bonded to a device,
 *         it only connects to the bonded device when several BTLE devices is nearby.
 *  @discussion The initialization call of iGate.
 *
 */
- (CiGate *)initWithDelegate:(id<CiGateDelegate>)aDelegate autoConnectFlag:(BOOL)aFlag BondDevUUID:(CFUUIDRef)bondDevUUID serviceUuidStr:(NSString*)uuidStr;

/*!
 *  @method startSearch:
 *
 *  @discussion Start search for device. If no bond UUID is set before startSearch,
 *              iGate will try to connect/bond to a new device.
 *
 */
- (void)startSearch;

/*!
 *  @method stopSearch:
 *
 *  @discussion Stop search for device.
 *
 */
- (void)stopSearch;

/*!
 *  @method connectDevice:deviceName:
 *
 *  @discussion Connect to a device by device UUID or device name.
 *              if devUUID is NULL, or the specified UUID doesn't match with any found devices,
 *              the deviceName will be used to search within the found devices, the first device
 *              whose name is matched will be connected. So if many devices around are with the
 *              the same name, it will connect to the one found firstly.
 *
 */
- (void)connectDevice:(CFUUIDRef)devUUID deviceName:(NSString *)name;

/*!
 *  @method getConnectDevName:
 *
 *  @discussion get the connected device name.
 *
 *
 */
- (NSString *) getConnectDevName;

/*!
 *  @method disconnectDevice:
 *
 *  @discussion While connected, use this method to disconnect the device.
 *  @see iGateDidUpdateState: , the iGateState will be idle after disconnect.
 *       And if iGate is inited with autoConnectFlag set to TRUE,
 *       a new search will be started.
 *       devUUID: the UUID of the connected device, it can be explictly set by the app,
 *       or NULL to let the lib choose the connected device.
 */
- (BOOL) disconnectDevice:(CFUUIDRef)devUUID;

/*!
 *  @method getConnectDevName:
 *
 *  @discussion get the connected device name.
 *               
 *
 */
- (void)sendData:(NSData *)data;

/*!
 *  @method retrieveIBeaconMajorNumber:
 *
 *  @discussion retrieve the connected device's iBeacon Major Number.
 */
@end

