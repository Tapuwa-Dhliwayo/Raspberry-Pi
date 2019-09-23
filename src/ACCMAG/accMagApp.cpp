#include <iostream>
#include <errno.h>
#include "accMagApp.h" //FXO8700 definitions required for setting up the sensor
#include <pigpio.h>

using namespace std;

#define BUFSIZE 13

int main(){

	/*
	char buffer1[BUFSIZE];
	char *buffer2;
	int temp;*/
	gpioCfgSetInternals(1<<10);
	gpioInitialise();
	
	accel_function();
	gyro_function();

	gpioTerminate();
}

void accel_function(){
	
	char *buffer;
	
	//Open up the i2c device FXOS8700
	int handle = i2cOpen(1,SENSOR1,0);

	int temp = i2cReadByteData(handle,FXOS8700_REGISTER_WHO_AM_I);
	//Checking that the device ID is accurate
	if(temp != SENSOR1_ID){
		cout << "There is an error with the device" <<endl;
		temp = i2cClose(handle);
		gpioTerminate();
		return 0;
	}
	//Set device to standby mode : Enables data readings
	i2cWriteWordData(handle,FXOS8700_REGISTER_CTRL_REG1,0);

	//Configure the accelerometer speed
	//Use one speed for now
	i2cWriteWordData(handle,FXOS8700_REGISTER_XYZ_DATA_CFG,0x02);
	//High Resolution
	i2cWriteWordData(handle,FXOS8700_REGISTER_CTRL_REG2, 0x02);
	//Active Normal Mode low Noise 100Hz in Hybrid Mode
	i2cWriteWordData(handle,FXOS8700_REGISTER_CTRL_REG1, 0x15);

	//Configure the magnetometer
	//Hybrid Mode, Over sampling = 16
	i2cWriteWordData(handle,FXOS8700_REGISTER_MCTRL_REG1, 0x1F);
	//Jump to reg 0x33 after reading 0x06
	i2cWriteWordData(handle,FXOS8700_REGISTER_MCTRL_REG2, 0x20);

	//Read 13 bytes of the sensor
	temp = i2cReadDevice(handle,buffer,13);

	//Creating proper integer values from the sensors
	int acc_x = (int16_t)((buffer[1] << 8) | buffer[2]) >> 2;
	int acc_y = (int16_t)((buffer[3] << 8) | buffer[4]) >> 2;
	int acc_z = (int16_t)((buffer[5] << 8) | buffer[6]) >> 2;
	int mag_x = (int16_t)((buffer[7] << 8) | buffer[8]);
	int mag_y = (int16_t)((buffer[9] << 8) | buffer[10]);
	int mag_z = (int16_t)((buffer[11] << 8) | buffer[12]);

	acc_x *= ACCEL_MG_LSB_8G * SENSORS_GRAVITY_STANDARD;
	acc_y *= ACCEL_MG_LSB_8G * SENSORS_GRAVITY_STANDARD;
	acc_z *= ACCEL_MG_LSB_8G * SENSORS_GRAVITY_STANDARD;

	mag_x *= MAG_UT_LSB;
	mag_y *= MAG_UT_LSB;
	mag_z *= MAG_UT_LSB;

	cout << acc_x << endl;
	cout << acc_y << endl;
	cout << acc_z << endl;
	cout << mag_x << endl;
	cout << mag_y << endl;
	cout << mag_z << endl;

	temp = i2cClose(handle);

}

void gyro_function(){
	
	char *buffer;

	//Open up the i2c device FXAS21002
	int handle = i2cOpen(1,SENSOR2,0);
	
	int temp = i2cReadByteData(handle,GYRO_REGISTER_WHO_AM_I);
	//Checking that the device ID is accurate
	if(temp != SENSOR2_ID){
		cout << "There is an error with the device" <<endl;
		temp = i2cClose(handle);
		gpioTerminate();
		return 0;
	}
	//Setting CTRL_REG : 1000DPS in this case
	uint8_t ctrlReg0 = 0x01;
	
	//Configuring Sensor
	/* Reset then switch to active mode with 100Hz output */
  	i2cWriteWordData(GYRO_REGISTER_CTRL_REG1, 0x00);     // Standby
 	i2cWriteWordData(GYRO_REGISTER_CTRL_REG1, (1<<6));   // Reset
  	i2cWriteWordData(GYRO_REGISTER_CTRL_REG0, ctrlReg0); // Set sensitivity
  	i2cWriteWordData(GYRO_REGISTER_CTRL_REG1, 0x0E);     // Active
	delay(100);
	
	temp = i2cReadDevice(handle,buffer,7);
	
	int gyro_x = (int16_t)((buffer[1] << 8) | buffer[2]);
	int gyro_y = (int16_t)((buffer[3] << 8) | buffer[4]);
	int gyro_z = (int16_t)((buffer[5] << 8) | buffer[6]);
	
	gyro_x *= GYRO_SENSITIVITY_1000DPS;
	gyro_y *= GYRO_SENSITIVITY_1000DPS;
	gyro_z *= GYRO_SENSITIVITY_1000DPS;
	
	gyro_x *= SENSORS_DPS_TO_RADS;
	gyro_y *= SENSORS_DPS_TO_RADS;
	gyro_z *= SENSORS_DPS_TO_RADS;
	
	cout << gyro_x << endl;
	Cout << gyro_y << endl;
	cout << gyro_z << endl;
	
	temp = i2cClose(handle);
	
}
