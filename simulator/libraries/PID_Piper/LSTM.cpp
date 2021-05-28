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
		return 0.5;
}

float LSTM::getPitchAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
		float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
		float velVarX, float velVarY, int navRoll, int navPitch, float airspeed)
{
		std::vector<float> input{(float)gyro.x, (float)gyro.y, (float)gyro.z, (float)pos.x, (float)pos.y, (float)pos.z, (float)mag.x, (float)mag.y, (float)mag.z, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, (float)navRoll, (float)navPitch};
		return 10;
}

float LSTM::getYawAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
		float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
		float velVarX, float velVarY, int navRoll, int navPitch, float airspeed)
{
		std::vector<float> input{(float)gyro.x, (float)gyro.y, (float)gyro.z, (float)pos.x, (float)pos.y, (float)pos.z, (float)mag.x, (float)mag.y, (float)mag.z, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, (float)navRoll, (float)navPitch};
		return 5;
}
*/

float LSTM::getRollAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
		float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
		float velVarX, float velVarY, int navRoll, int navPitch, float airspeed)
{
		const auto model = fdeep::load_model("/home/pritamdash/Documents/Project/UAV-False-Data/ardupilot/libraries/PID_Piper/models/roll.json");
		std::vector<float> input{acc.x, acc.y, acc.z, gyro.x, gyro.y, gyro.z, pos.x, pos.y, pos.z, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, (float)navRoll, (float)navPitch};
		int roll = model.predict_single_output({fdeep::tensor(fdeep::tensor_shape(1,18), input)});
		return (float) roll;
}


float LSTM::getPitchAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
		float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
		float velVarX, float velVarY, int navRoll, int navPitch, float airspeed)
{
		const auto model = fdeep::load_model("/home/pritamdash/Documents/Project/UAV-False-Data/ardupilot/libraries/PID_Piper/models/pitch.json");
		std::vector<float> input{(float)gyro.x, (float)gyro.y, (float)gyro.z, (float)pos.x, (float)pos.y, (float)pos.z, (float)mag.x, (float)mag.y, (float)mag.z, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, (float)navRoll, (float)navPitch};

		const auto pitch = model.predict_single_output({fdeep::tensor(fdeep::tensor_shape(1,18), input)});
		return (float)pitch;
}

float LSTM::getYawAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
		float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
		float velVarX, float velVarY, int navRoll, int navPitch, float airspeed)
{
		const auto model = fdeep::load_model("/home/pritamdash/Documents/Project/UAV-False-Data/ardupilot/libraries/PID_Piper/models/yaw.json");
		std::vector<float> input{(float)gyro.x, (float)gyro.y, (float)gyro.z, (float)pos.x, (float)pos.y, (float)pos.z, (float)mag.x, (float)mag.y, (float)mag.z, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, (float)navRoll, (float)navPitch};

		const auto yaw = model.predict_single_output({fdeep::tensor(fdeep::tensor_shape(1,18), input)});
		return (float)yaw;
}

