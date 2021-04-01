#ifndef PID_PIPER_H
#define PID_PIPER_H
#include<iostream>
#include<fstream>
using namespace std;
#include<stdio.h>
#include "LSTM.h"

class PID_Piper
{
	/*float posX, posY, posZ;
	float accX, accY, accZ;
	float gyroX, gyroY, gyroZ;
	float magX, magY, magZ;
	//float lat, lon, alt;
	float gpsVel;
	float ahrsRP, ahrsYaw;
	float posVarH, posVarV;
	float velVarX, velVarY, compassVar;
	int navRoll, navPitch;
	float airspeed;*/
	LSTM _lstm;
	public:
		static Vector3f acc;
		static Vector3f pos;
		static Vector3f gyro;
		static Vector3f mag;
		static Vector3f posControl;
		static Vector3f eulerSpeed;
		static float gpsVel;
		static float ahrsRP, ahrsYaw;
		static float posVarH, posVarV;
		static float velVarX, velVarY;
		static int navRoll, navPitch;
		static float airspeed;

		Vector3f y_ML;
		Vector3f y_PID;
		double delta[3] = {0,0,0};
		double threshold[3] = {18, 18.09, 18.6};
		double b[3] = {0,0,0};
		double residual[3];
		bool recoveryMode = false;

		static void getPosControlXY(float _accX, float _accY,
									float _gyroX, float _gyroY, float _gyroZ,
									float _posX, float _posY, float _posZ,
									float _velX, float _ahrsRP, float _ahrsYaw,
									float _errorX, float _errorY, float _velErrorX, float _velErrorY,
									int _navRoll, int _navPitch)
		{
			PID_Piper::acc.x = _accX;
			PID_Piper::acc.y = _accY;
			PID_Piper::gyro.x = _gyroX;
			PID_Piper::gyro.y = _gyroY;
			PID_Piper::gyro.z = _gyroZ;
			PID_Piper::pos.x = _posX;
			PID_Piper::pos.y = _posY;
			PID_Piper::pos.z = _posZ;
			PID_Piper::gpsVel = _velX;
			PID_Piper::ahrsRP = _ahrsRP;
			PID_Piper::ahrsYaw = _ahrsYaw;
			PID_Piper::posVarH = _errorX;
			PID_Piper::posVarV = _errorY;
			PID_Piper::velVarX = _velErrorX;
			PID_Piper::velVarY = _velErrorY;
			PID_Piper::navRoll = _navRoll;
			PID_Piper::navPitch = _navPitch;
		}
		static void getPosControlZ(float _accZ)
		{
			PID_Piper::acc.z = _accZ;
		}

		static void getMagnetometerData(float _x, float _y, float _z)
		{
			PID_Piper::mag.x = _x;
			PID_Piper::mag.y = _y;
			PID_Piper::mag.z = _z;
		}

		static void getAirSpeed(float _airspeed)
		{
			PID_Piper::airspeed = _airspeed;
		}

		void getEulerAngle()
		{
			this->y_ML.x = _lstm.getRollAngle(acc, gyro, pos, mag, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, navRoll, navPitch, airspeed);
			this->y_ML.y = _lstm.getPitchAngle(acc, gyro, pos, mag, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, navRoll, navPitch, airspeed);
			this->y_ML.z = _lstm.getYawAngle(acc, gyro, pos, mag, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, navRoll, navPitch, airspeed);

		}

		void cusum(double error[3])
		{
			residual[0] = error[0];
			residual[1] = error[1];
			residual[2] = error[2];

		    for(int i =0;i<3;i++)
		    {
		        if(delta[i]+residual[i]-b[i]<0)
		            delta[i]=0;
		        else
		            delta[i]+=(residual[i]-b[i]);
		    }

		    for(int i=0;i<9;i++)
		    {
		        if(delta[i]>threshold[i])
		            recoveryMode = true;
		    }

		}

		bool checkSwitchControl()
		{
			if(abs(residual[0] - b[0]) < 0.1 && abs(residual[1]- b[1] < 0.1 && abs(residual[2] - b[2]) < 0.1))
			{
				recoveryMode = false;
			}
			return recoveryMode;
		}

		Vector3f recoveryMonitor()
		{
			//difference between ML and PID
			residual[0] = abs(y_ML.x - y_PID.x);
			residual[1] = abs(y_ML.y - y_PID.y);
			residual[2] = abs(y_ML.z - y_PID.z);

			//check cusum
			cusum(residual);

			if(recoveryMode)
			{
				return y_ML;
				//check if attack subsides
				recoveryMode = checkSwitchControl();
				if(!recoveryMode)
					return y_PID;
			}
			return y_PID;
		}
};

#endif
