
/*!
 *  @file Adafruit_ISM330DHCT.cpp Adafruit ISM330DHCT 6-DoF Accelerometer
 *  and Gyroscope library
 *
 *  Bryan Siepert for Adafruit Industries
 * 	BSD (see license.txt)
 */

#include "Arduino.h"
#include <Wire.h>

#include "Adafruit_ISM330DHCT.h"

/*!
 *    @brief  Instantiates a new ISM330DHCT class
 */
Adafruit_ISM330DHCT::Adafruit_ISM330DHCT(void) {}

bool Adafruit_ISM330DHCT::_init(int32_t sensor_id) {
  // make sure we're talking to the right chip
  if (chipID() != ISM330DHCT_CHIP_ID) {
    return false;
  }
  _sensorid_accel = sensor_id;
  _sensorid_gyro = sensor_id + 1;
  _sensorid_temp = sensor_id + 2;

  reset();

  // enable accelerometer and gyro by setting the data rate to non-zero
  setAccelDataRate(LSM6DS_RATE_104_HZ);
  setGyroDataRate(LSM6DS_RATE_104_HZ);

  delay(10);

  temp_sensor = new Adafruit_LSM6DS_Temp(this);
  accel_sensor = new Adafruit_LSM6DS_Accelerometer(this);
  gyro_sensor = new Adafruit_LSM6DS_Gyro(this);

  return true;
}
