/*
 * This library uses frugally-deep header only library written by Tobias Hermann
 * https://github.com/Dobiasd/frugally-deep
 */

#include "LSTM.h"
#include <fdeep/fdeep.hpp>
/*
float LSTM::getRollAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
		float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
		float velVarX, float velVarY, int navRoll, int navPitch, float airspeed)
{
		std::vector<float> input{(float)gyro.x, (float)gyro.y, (float)gyro.z, (float)pos.x, (float)pos.y, (float)pos.z, (float)mag.x, (float)mag.y, (float)mag.z, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, (float)navRoll, (float)navPitch};
		return 50.55555;
}

float LSTM::getPitchAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
		float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
		float velVarX, float velVarY, int navRoll, int navPitch, float airspeed)
{
		std::vector<float> input{(float)gyro.x, (float)gyro.y, (float)gyro.z, (float)pos.x, (float)pos.y, (float)pos.z, (float)mag.x, (float)mag.y, (float)mag.z, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, (float)navRoll, (float)navPitch};
		return 10.2222;
}

float LSTM::getYawAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
		float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
		float velVarX, float velVarY, int navRoll, int navPitch, float airspeed)
{
		std::vector<float> input{(float)gyro.x, (float)gyro.y, (float)gyro.z, (float)pos.x, (float)pos.y, (float)pos.z, (float)mag.x, (float)mag.y, (float)mag.z, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, (float)navRoll, (float)navPitch};
		return 30.2222;
}
*/

float LSTM::getRollAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
		float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
		float velVarX, float velVarY, int navRoll, int navPitch, float airspeed)
{
		std::vector<float> input{acc.x, acc.y, acc.z, gyro.x, gyro.y, gyro.z, pos.x, pos.y, pos.z, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, (float)navRoll, (float)navPitch};
		float roll = rollModel.predict_single_output({fdeep::tensor(fdeep::tensor_shape(18), input)});
		return roll;
}

float LSTM::getPitchAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
		float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
		float velVarX, float velVarY, int navRoll, int navPitch, float airspeed)
{
		std::vector<float> input{acc.x, acc.y, acc.z, gyro.x, gyro.y, gyro.z, pos.x, pos.y, pos.z, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, (float)navRoll, (float)navPitch};

		float pitch = pitchModel.predict_single_output({fdeep::tensor(fdeep::tensor_shape(18), input)});
		return pitch;
}

float LSTM::getYawAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
		float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
		float velVarX, float velVarY, int navRoll, int navPitch, float airspeed)
{
		std::vector<float> input{acc.x, acc.y, acc.z, gyro.x, gyro.y, gyro.z, pos.x, pos.y, pos.z, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, (float)navRoll, (float)navPitch};

		float yaw = (int) yawModel.predict_single_output({fdeep::tensor(fdeep::tensor_shape(18), input)});
		return yaw;
}

