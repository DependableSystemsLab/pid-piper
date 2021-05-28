#ifndef O_PID_PIPER_H
#define O_PID_PIPER_H
#include<iostream>
#include<fstream>
using namespace std;
#include<stdio.h>
#include <AP_Math/AP_Math.h>

class O_PID_Piper
{
private:
    //static ofstream myfile;
    static const int file = 22;

public:
    static void write_to_file_piper(Vector3f piper, Vector3f pid)
    {
        ofstream myfile;
        string filename = "Data_Piper_"+std::to_string(file)+".csv";
        myfile.open(filename, std::ios::app);
        myfile<<pid.x <<","<<pid.y<<","<<pid.z<<","<<piper.x <<","<<piper.y<<","<<piper.z;
        myfile<<endl;
    }
    static void write_to_file_sensor(float accel_target_x, float accel_target_y,
		float ahrs_gyro_x, float ahrs_gyro_y, float ahrs_gyro_z,
		float curr_pos_x, float curr_pos_y, float curr_pos_z,
		float vehicle_horiz_vel_x, float ahrs_error, float ahrs_error_yaw,
		float pos_error_x, float pos_error_y,
		float vel_error_x, float vel_error_y,
		float roll_sensor, float pitch_sensor)
    {
    	ofstream myfile;
		string filename = "Data_Piper_Sensor_"+std::to_string(file)+".csv";
		myfile.open(filename, std::ios::app);
		myfile<<accel_target_x<<","<<accel_target_y<<","<<ahrs_gyro_x<<","<<ahrs_gyro_y<<","<<ahrs_gyro_z<<","
			  <<curr_pos_x<<","<<curr_pos_y<<","<<curr_pos_z<<","
		      <<vehicle_horiz_vel_x<<","<<ahrs_error<<","<<ahrs_error_yaw<<","
			  <<pos_error_x<<","<<pos_error_y<<","
			  <<vel_error_x<<","<<vel_error_y<<","
			  <<roll_sensor<<","<<pitch_sensor;
		myfile<<endl;
    }
    static void write_to_file_piper(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag, float gpsVel,
    								float ahrsRP, float ahrsYaw, float posVarH, float posVarV, float velVarX,
									float velVarY, int navRoll, int navPitch, float airspeed, Vector3f yPID)
    {
    	ofstream myfile;
		string filename = "Data_Piper_Sensor_Piper_"+std::to_string(file)+".csv";
		myfile.open(filename, std::ios::app);
		myfile<<acc.x<<","<<acc.y<<","<<acc.z<<","<<gyro.x<<","<<gyro.y<<","<<gyro.z<<","
			  <<pos.x<<","<<pos.y<<","<<pos.z<<","<<mag.x<<","<<mag.y<<","<<mag.z<<","
			  <<gpsVel<<","<<ahrsRP<<","<<ahrsYaw<<","<<posVarH<<","<<posVarV<<","
			  <<velVarX<<","<<velVarY<<","
			  <<navRoll<<","<<navPitch<<","<<airspeed<<","
			  <<yPID.x<<","<<yPID.y<<","<<yPID.z;
		myfile<<endl;
    }
};

#endif

