#include "LSTM.h"
#include <AP_Math/AP_Math.h>
#include <vector>

float LSTM::getRollAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
		float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
		float velVarX, float velVarY, int navRoll, int navPitch, float airspeed)
{
		std::vector<float> input{(float)gyro.x, (float)gyro.y, (float)gyro.z, (float)pos.x, (float)pos.y, (float)pos.z, (float)mag.x, (float)mag.y, (float)mag.z, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, (float)navRoll, (float)navPitch};
		return 0.21;
}

float LSTM::getPitchAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
		float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
		float velVarX, float velVarY, int navRoll, int navPitch, float airspeed)
{
		std::vector<float> input{(float)gyro.x, (float)gyro.y, (float)gyro.z, (float)pos.x, (float)pos.y, (float)pos.z, (float)mag.x, (float)mag.y, (float)mag.z, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, (float)navRoll, (float)navPitch};
		return 0.1;
}

float LSTM::getYawAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
		float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
		float velVarX, float velVarY, int navRoll, int navPitch, float airspeed)
{
		std::vector<float> input{(float)gyro.x, (float)gyro.y, (float)gyro.z, (float)pos.x, (float)pos.y, (float)pos.z, (float)mag.x, (float)mag.y, (float)mag.z, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, (float)navRoll, (float)navPitch};
		return 0.0;
}


float LSTM::getRollAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
		float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
		float velVarX, float velVarY, int navRoll, int navPitch, float airspeed)
{
		const auto model = fdeep::load_model("models/roll.json");
		std::vector<float> input{(float)gyro.x, (float)gyro.y, (float)gyro.z, (float)pos.x, (float)pos.y, (float)pos.z, (float)mag.x, (float)mag.y, (float)mag.z, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, (float)navRoll, (float)navPitch};

		const auto roll = model.predict_single_output({fdeep::tensor(fdeep::tensor_shape(1,18), input)});
		return roll;
}

float LSTM::getPitchAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
		float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
		float velVarX, float velVarY, int navRoll, int navPitch, float airspeed)
{
		const auto model = fdeep::load_model("models/pitch.json");
		std::vector<float> input{(float)gyro.x, (float)gyro.y, (float)gyro.z, (float)pos.x, (float)pos.y, (float)pos.z, (float)mag.x, (float)mag.y, (float)mag.z, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, (float)navRoll, (float)navPitch};

		const auto pitch = model.predict_single_output({fdeep::tensor(fdeep::tensor_shape(1,18), input)});
		return pitch;
}

float LSTM::getYawAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
		float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
		float velVarX, float velVarY, int navRoll, int navPitch, float airspeed)
{
		const auto model = fdeep::load_model("models/yaw.json");
		std::vector<float> input{(float)gyro.x, (float)gyro.y, (float)gyro.z, (float)pos.x, (float)pos.y, (float)pos.z, (float)mag.x, (float)mag.y, (float)mag.z, gpsVel, ahrsRP, ahrsYaw, posVarH, posVarV, velVarX, velVarY, (float)navRoll, (float)navPitch};

		const auto yaw = model.predict_single_output({fdeep::tensor(fdeep::tensor_shape(1,18), input)});
		return yaw;
}
