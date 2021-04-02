#include <AP_Math/AP_Math.h>
class NModel
{
	Vector3f targetAngle;
	double w1 [22] = {-1.92005,
				1.6472381,
				-0.72702557,
				-0.25149593,
				0.6558364,
				-1.5636764,
				-1.4470158,
				0.00856243,
				1.7055755,
				-0.9763711,
				0.283647,
				2.331934,
				-0.02616078,
				-0.9849684,
				1.4031961,
				0.60556114,
				0.11718512,
				0.08995898,
				-1.2352622,
				0.74591905,
				-0.85679686,
				0.8400537};
	double b1= 1.007396;

	float getRollAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
			float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
			float velVarX, float velVarY, int navRoll, int navPitch, float airspeed)
	{
		targetAngle.x = acc.x*w1[0] + acc.y*w1[1] + acc.z*w1[2] +
						gyro.x*w1[3] + gyro.y*w1[4] + gyro.z*w1[5] +
						pos.x*w1[6] + pos.y*w1[7] + pos.z*w1[8] +
						mag.x*w1[9] + mag.y*w1[10] + mag.z*w1[11] +
						gpsVel*w1[12] + ahrsRP*w1[13]+ ahrsYaw*w1[14] +
						posVarH*w1[15] + posVarV*w1[16] + velVarX*w1[17] +
						velVarY*w1[18] + navRoll*w1[19] + navPitch*w1[20] +
						airspeed*w1[21] + b1;
		return targetAngle.x;
	}
	float getPitchAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
			float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
			float velVarX, float velVarY, int navRoll, int navPitch, float airspeed)
	{
		targetAngle.y = acc.x*w1[0] + acc.y*w1[1] + acc.z*w1[2] +
								gyro.x*w1[3] + gyro.y*w1[4] + gyro.z*w1[5] +
								pos.x*w1[6] + pos.y*w1[7] + pos.z*w1[8] +
								mag.x*w1[9] + mag.y*w1[10] + mag.z*w1[11] +
								gpsVel*w1[12] + ahrsRP*w1[13]+ ahrsYaw*w1[14] +
								posVarH*w1[15] + posVarV*w1[16] + velVarX*w1[17] +
								velVarY*w1[18] + navRoll*w1[19] + navPitch*w1[20] +
								airspeed*w1[21] + b1;
		return targetAngle.y;
	}
	float getYawAngle(Vector3f acc, Vector3f gyro, Vector3f pos, Vector3f mag,
			float gpsVel, float ahrsRP, float ahrsYaw, float posVarH, float posVarV,
			float velVarX, float velVarY, int navRoll, int navPitch, float airspeed)
	{
		targetAngle.z = acc.x*w1[0] + acc.y*w1[1] + acc.z*w1[2] +
								gyro.x*w1[3] + gyro.y*w1[4] + gyro.z*w1[5] +
								pos.x*w1[6] + pos.y*w1[7] + pos.z*w1[8] +
								mag.x*w1[9] + mag.y*w1[10] + mag.z*w1[11] +
								gpsVel*w1[12] + ahrsRP*w1[13]+ ahrsYaw*w1[14] +
								posVarH*w1[15] + posVarV*w1[16] + velVarX*w1[17] +
								velVarY*w1[18] + navRoll*w1[19] + navPitch*w1[20] +
								airspeed*w1[21] + b1;
		return targetAngle.z;
	}
};
