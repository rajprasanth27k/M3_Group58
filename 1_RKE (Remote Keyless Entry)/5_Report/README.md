# Remote Keyless Entry (RKE)

## Tabel of Content
  1. Description
  2. High Level Reuqirements
  3. Low Level Reuqirements
  4. SWOT Analysis
  5. 5Ws and 1H
  
## 1. Description

Remote keyless entry (RKE) is a system designed to remotely control the access to a building or vehicle etc. RKE transmission requires two components: Transmitter(RKE key fob) to send radio frequency signal and a Receiver(Body Control ECU) to receive the signal. RKE system allows a user to lock, open the trunk and unlock the car using a transmitter on the key-fob, which transmits data to a receiver in the vehicle. Here the signal is sent as encrypted data from the key-fob to the particular car.

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

## 4. SWOT Analysis

![Swot drawio](https://user-images.githubusercontent.com/98897973/157901474-c4081d54-c116-48b1-ae5c-fe8af0500f3f.png)

## 5. 5Ws and 1H
![5w1h](https://user-images.githubusercontent.com/98897973/157901806-e178260d-a9fc-4721-85b3-9963bb6515d6.png)

# Architecture
## Behavioural Diagram

* High Level Flow chart Behavioral Diagram

![FL1 drawio](https://user-images.githubusercontent.com/98897973/157926269-ff80fc4b-be02-4f0d-9cec-4caa74c258b3.png)

##
* Low Level Flow chart Behavioral Diagram

![FL2 drawio](https://user-images.githubusercontent.com/98897973/157925917-fb626ae6-7316-4b89-962a-c06854b13388.png)


