#ifndef LSTM_H
#define LSTM_H

#include <AP_Math/AP_Math.h>

class LSTM
{
	public:
		Vector3f targetAngle;

		float getRollAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
				float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
				float velVarX, float velVarY, int navRoll, int navPitch, float airspeed);

		float getPitchAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
				float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
				float velVarX, float velVarY, int navRoll, int navPitch, float airspeed);

		float getYawAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
				float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
				float velVarX, float velVarY, int navRoll, int navPitch, float airspeed);
};
#endif
