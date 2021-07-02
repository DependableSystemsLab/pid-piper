/*
 * This library uses frugally-deep header only library written by Tobias Hermann
 * https://github.com/Dobiasd/frugally-deep
 */
#ifndef LSTM_H
#define LSTM_H

#include <AP_Math/AP_Math.h>
#include <fdeep/fdeep.hpp>

class LSTM
{
	private:
		Vector3f targetAngle;

		fdeep::model loadRollModel() {
			return fdeep::load_model("/home/pritamdash/Documents/PID-Piper/pid-piper/simulator/libraries/PID_Piper/models/roll-nn.json");
		}
		fdeep::model loadPitchModel() {
			return fdeep::load_model("/home/pritamdash/Documents/PID-Piper/pid-piper/simulator/libraries/PID_Piper/models/pitch-nn.json");
		}
		fdeep::model loadYawModel() {
			return fdeep::load_model("/home/pritamdash/Documents/PID-Piper/pid-piper/simulator/libraries/PID_Piper/models/yaw-nn.json");
		}

	public:
		const fdeep::model rollModel = loadRollModel();
		const fdeep::model pitchModel = loadPitchModel();
		const fdeep::model yawModel = loadYawModel();

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

