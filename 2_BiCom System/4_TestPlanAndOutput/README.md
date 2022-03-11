# TestPlanAndOutput
## HIGH LEVEL TEST PLAN
|TestID|Description|Input|Output|Status|
|------|--------|--------|-------|-----|
|01|Encryption|Only authorized key can access the Car control | Authorized key has accessed the Car control | Passed |
|02|Car Locking|switch pressed 1 times|Car  Locked| Passed |
|03|Car unlocking|switch pressed 2 times|Car  unlocked| Passed |
|04|Alarm Activation|switch pressed 3 times|Alarm Activated| Passed |
|05|Alarm deactivation|switch pressed 3 times|Alarm deactivated| Passed |
|06|Approach Light|switch pressed 4 times|Approach Light Turned ON| Passed |

## LOW LEVEL TEST PLAN
|TestID|Description|Input|Output|Status|
|------|--------|--------|-------|--------|
|01|Check all LEDs Should get turn ON together when Car is locked|switch pressed 1 times |All Leds are ON| Passed |
|02|Check all LEDs Should get turn OFF together when Car is unlocked |switch pressed 2 times |All Leds are OFF| Passed |
|03|Check Alarm Activation|switch pressed 3 time |LEDs turned ON one by one in clockwise direction | Passed |
|04|Check Alarm deactivation|switch pressed 3 time |LEDs turned OFF one by one in clockwise direction | Passed |
|05|Check Light Approach |switch pressed 4 time |LEDs turned ON one by one in anticlockwise direction | Passed |



