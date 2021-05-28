# PID-Piper Recovery Framework
This repo contains the PID-Piper recovery framework code and dataset used in the PID-Piper DSN'21 paper. 
- /Dataset contains attack-free and with-attack UAV traces, both for FFC and FBC controller design. 
- /Simulator contains PID-Piper implementation in ArduPilot SITL. 

We have provided a docker image to build the simulator and run missions to test PID-Piper.  

## Building the Docker image
Clone the project
```bash
git clone https://github.com/DependableSystemsLab/pid-piper.git
cd pid-piper
```
Build docker image
```bash
docker build -t pid-piper Dockerfile/.
```
## Running the Simulator
We have provided a script to run the simulator with the map view and the console.  
```bash
./startSimulator.sh copter --console --map
```
The simulator can also be executed by running the docker image and then following the steps given here http://ardupilot.org/dev/docs/setting-up-sitl-on-linux.html 

## Running ArduPilot locally
To use a local copy of ArduPilot follow these steps:
* Clone the Project
* Install the [pre-requisites](https://github.com/DependableSystemsLab/stealthy-attacks/tree/master/Simulator/ardupilot-attack-version/Tools/environment_install)
* Run ardupilot locally
```bash
cd simulator/ArduCopter
../Tools/autotest/sim_vehicle.py --console --map
```
Follow the steps given [here](http://ardupilot.org/dev/docs/copter-sitl-mavproxy-tutorial.html) to setup the build environment. 

## Launch Missions
To run a mission, use this command:
```bash
wp load ../Tools/autotest/mission/mission-1.txt
mode guided
arm throttle
takeoff 10
mode auto
```
The above script will launch overt attacks intermittently during the mission. The effects of the attack and the recovery can be seen by zooming in to the map window. Videos showing PID-Piper recovery on real RVs are available [here](https://drive.google.com/drive/folders/1GG03mz_0IkC_D91Z9UN3HsluzHrwVNVU). 

## PID-Piper code and ML models
The attack detection and recovery code is implemented as a library available at simulator/libraries/PID-Piper. The ML model are available under /models.

## Dataset
Please contain pdash@ece.ubc.ca if you need the raw .tlog files. 

## Paper
If you find the repo useful, please cite the following paper: 

*Pritam Dash, Guanpeng Li, Zitao Chen, Mehdi Karimibiuki, and Karthik Pattabiraman, "PID-Piper: Recoverying Robotic Vehicles from Physical Attacks", 51st IEEE/IFIP International Conference on Dependable Systems and Networks (DSN), 2021.*
