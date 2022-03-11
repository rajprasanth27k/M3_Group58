# BICom SYSTEM
## 1_DESCRIPTION
This project is bicom system where it is bidirectional.BiCom functions by bidirectionally transmitting radio waves on a certain frequency, and it also displays the full car state on an LED, allowing us to control all aspects of an automobile.
## 2_Identifying features
When the Button is pressed one time, this should show the car's window status.

When the Button is pressed two times, this should show the car's alarm status.

When the button is pressed three times, this should show cars battery information.

When the Button is pressed FOUR times, this should show the car's door status.

## 3_State of art
Status of the car need to be known when buttons are pressed

Buttons will be provided to make it easier to access the functionalities that are accessible.

## 4_SWOT ANALYSIS
![Swot analysis](swot.png)
## 5_ 4W's & 1H
![ 4W's & 1H](4w.png)

## 2. High Level Requirements
|ID|Description|
|------|------|
|HLR_01|RKE key fob shall send signal to the car ECU |
|HLR_02|The Car shall get locked |
|HLR_02|The Car shall get Unlocked |
|HLR_03|The Car alarm shall get activated/deactivated |
|HLR_04|Car Approach Light shall get activated on pressing Key-fob |

## 3. Low Level Requirements
|ID|ID|Description|
|------|------|------|
|HLR_01|LLR_01|Keyfob shall be in detectable range of the car|
||LLR_02|RemoteKey Battery must be Working |
|HLR_02|LLR_01|System shall print message "Lock" |       
||LLR_02|All LED lights shall get turned on at the same time|
|HLR_03|LLR_01|System shall print message "Unlock"|              
||LLR_02|All LED lights shall get turned off at the same time|
|HLR_04|LLR_01|System shall print message "Alarm Activated/Deactivated"|              
||LLR_02|All led shall get turned on in clockwise manner|
|HLR_04|LLR_01|System shall print message "Approach Light"|              
||LLR_02|All led shall get turned on in anti-clockwise manner|
