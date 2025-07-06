/*!
 *  @file Adafruit_BNO08x.h
 *
 * 	I2C Driver for the Adafruit BNO08x 9-DOF Orientation IMU Fusion Breakout
 *
 * 	This is a library for the Adafruit BNO08x breakout:
 * 	https://www.adafruit.com/products/4754
 *
 * 	Adafruit invests time and resources providing this open source code,
 *  please support Adafruit and open-source hardware by purchasing products from
 * 	Adafruit!
 *
 *
 *	BSD license (see license.txt)
 */

#ifndef _SYULIMETRACKER_BNO08x_H
#define _SYULIMETRACKER_BNO08x_H

#include "Arduino.h"
#include "sh2.h"
#include "sh2_SensorValue.h"
#include "sh2_err.h" #include "../../SyulimeTracker_BusIO/SyulimeTracker_BusIO_Register.h"
#include "../../SyulimeTracker_BusIO/SyulimeTracker_I2CDevice.h"
#include "Adafruit_Sensor.h"
#include <Wire.h>

#define BNO08x_I2CADDR_DEFAULT 0x4A ///< The default I2C address

/* Additional Activities not listed in SH-2 lib */
#define PAC_ON_STAIRS 8 ///< Activity code for being on stairs
#define PAC_OPTION_COUNT \
  9 ///< The number of current options for the activity classifier

/*!
 *    @brief  Class that stores state and functions for interacting with
 *            the BNO08x 9-DOF Orientation IMU Fusion Breakout
 */
class SyulimeTracker_BNO08x
{
public:
  SyulimeTracker_BNO08x(int sda = -1, int scl = -1, int8_t reset_pin = -1);
  ~SyulimeTracker_BNO08x();

  bool begin_I2C(uint8_t i2c_addr = BNO08x_I2CADDR_DEFAULT,
                 TwoWire *wire = &Wire, int32_t sensor_id = 0);
  bool begin_UART(HardwareSerial *serial, int32_t sensor_id = 0);

  bool begin_SPI(uint8_t cs_pin, uint8_t int_pin, SPIClass *theSPI = &SPI,
                 int32_t sensor_id = 0);

  void hardwareReset(void);
  bool wasReset(void);

  bool enableReport(sh2_SensorId_t sensor, uint32_t interval_us = 10000);
  bool getSensorEvent(sh2_SensorValue_t *value);

  sh2_ProductIds_t prodIds; ///< The product IDs returned by the sensor

protected:
  virtual bool _init(int32_t sensor_id);

  sh2_Hal_t
      _HAL; ///< The struct representing the SH2 Hardware Abstraction Layer

private:
  int _sda;          ///< SDA pin number for I2C
  int _scl;          ///< SCL pin number for I2C
  int8_t _reset_pin; ///< Reset pin number
};

#endif
