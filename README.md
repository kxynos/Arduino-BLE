# Arduino-BLE
by Konstantinos Xynos (2018)

Some sample Arduino code I have hacked together. 

## [on-off-ble-demo.ino](https://github.com/kxynos/Arduino-BLE/blob/master/on-off-ble-demo.ino)
This allows for a HM-10 Bluetooth LE (BLE) module plugged into pins 7 and 8 (see below) to turn on and off the built-in light
The built-in light is off by default. 
Get an app that supports BLE and send one or zero to turn on or off the light. 

## [Waveshare-AlphaBot-car-HM10-bluetooth.ino](https://github.com/kxynos/Arduino-BLE/blob/master/Waveshare-AlphaBot-car-HM10-bluetooth.ino)
Modified version of the Waveshare AlphaBot car Bluetooth code for Arduino to support Bluetooth LE (BLE) module (HM-10) and mobile app commands. 

TIPS (issues I came across): 
* Check the baudrate of the BLE module (mine was set to 9600, so the code was modified)
* Make sure the commands are coming through. Check the debug strings in the code and check output in Serial Monitor. 
