#include "PID_Piper.h"
#include "../../ArduCopter/O_PID_Piper.h"

/*
void PID_Piper::PID_Piper(const PID_Piper &obj)
{
		acc = obj.acc;
		gyro = obj.gyro;
		pos = obj.gyro;
		mag = obj.mag;
		gpsVel = obj.gpsVel;
		ahrsRP = obj.ahrsRP;
		ahrsYaw = obj.ahrsYaw;
		posVarH = obj.posVarH;
		posVarV = obj.posVarV;
		velVarX = obj.velVarX;
		velVarY = obj.velVarY;
		navRoll = obj.navRoll;
		navPitch = obj.navPitch;
}
*/
void PID_Piper::getAirSpeed(float _airspeed)
{
		airspeed = _airspeed;
}

void PID_Piper::getPosControlXY(float _accX, float _accY, float _accZ,
		float _gyroX, float _gyroY, float _gyroZ,
		float _posX, float _posY, float _posZ,
		float _velX, float _ahrsRP, float _ahrsYaw,
		float _errorX, float _errorY, float _velErrorX, float _velErrorY,
		int _navRoll, int _navPitch)
{
		acc.x = _accX;
		acc.y = _accY;
		acc.z = _accZ;
		gyro.x = _gyroX;
		gyro.y = _gyroY;
		gyro.z = _gyroZ;
		pos.x = _posX;
		pos.y = _posY;
		pos.z = _posZ;
		gpsVel = _velX;
		ahrsRP = _ahrsRP;
		ahrsYaw = _ahrsYaw;
		posVarH = _errorX;
		posVarV = _errorY;
		velVarX = _velErrorX;
		velVarY = _velErrorY;
		navRoll = _navRoll;
		navPitch = _navPitch;
}

void PID_Piper::getPosControlZ(float _accZ)
{
	acc.z = _accZ;
}

void PID_Piper::getMagnetometerData(float _x, float _y, float _z)
{
	mag.x = _x;
	mag.y = _y;
	mag.z = _z;
}

Vector3f PID_Piper::getEulerAngle()
{
	y_ML.x = _lstm.getRollAngle(acc, gyro, pos, mag, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, navRoll, navPitch, airspeed);
	y_ML.y = _lstm.getPitchAngle(acc, gyro, pos, mag, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, navRoll, navPitch, airspeed);
	y_ML.z = _lstm.getYawAngle(acc, gyro, pos, mag, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, navRoll, navPitch, airspeed);

	return y_ML;
}

void PID_Piper::cusum(double error[3])
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

	for(int i=0;i<3;i++)
	{
		if(delta[i]>threshold[i])
			recoveryMode = true;
	}

}

bool PID_Piper::checkSwitchControl()
{
	if(abs(residual[0] - b[0]) < 0.1 && abs(residual[1]- b[1] < 0.1 && abs(residual[2] - b[2]) < 0.1))
	{
		recoveryMode = false;
	}
	return recoveryMode;
}

Vector3f PID_Piper::recoveryMonitor()
{
	y_ML = getEulerAngle();
	/*
	y_PID.x = angle_pid.x;
	y_PID.y = angle_pid.y;
	y_PID.z = angle_pid.z;
	*/

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
/*
void PID_Piper::write_to_file(Vector3f a, Vector3f g, Vector3f p, Vector3f m, float gV, float aRP, float aYaw, float pVarH, float pVarV, float vVarX, float vVarY, int nRoll, int nPitch, float aspeed)
{
	O_PID_Piper::write_to_file_piper(a, g, p, m, gV, aRP, aYaw, pVarH, pVarV, vVarX, vVarY, nRoll, nPitch, aspeed, y_PID);
}
*/








