# TestPlanAndOutput
## HIGH LEVEL TEST PLAN
|TestID|Description|Input|Output|Status|
|------|--------|--------|-------|-----|
|01|Encryption|Only authorized key can access the Car control | Authorized key has accessed the Car control | Passed/Not |
|02|Car Locking|switch pressed 1 times|Window status of the car| Passed |
|03|Car unlocking|switch pressed 2 times|Alarm ststus of the car| Passed |
|04|Alarm Activation|switch pressed 3 times|Battery status of the car| Passed |
|05|Alarm deactivation|switch pressed 3 times|battery status of the car| Passed |
|06|Approach Light|switch pressed 4 times|Door status of the car| Passed |

## LOW LEVEL TEST PLAN
|TestID|Description|Input|Output|Status|
|------|--------|--------|-------|--------|
|01|Check for window status|switch pressed 1 times |All Leds are ON| Passed |
|02|Check for alarm ststus |switch pressed 2 times |All Leds are OFF| Passed |
|03|Check for battery status |switch pressed 3 times | All led on once anticlockwise | Passed |
|04|Check for door status|switch pressed 4 times | All led on once clockwise |Passed |


