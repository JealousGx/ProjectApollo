/*
 *   ESP32 Oxygen Concentrator
 *  ===========================
 * 
 * This software is provided "as is" for educational purposes only. 
 * No claims are made regarding its fitness for medical or any other purposes. 
 * The authors are not liable for any injuries, damages or financial losses.
 * 
 * Use at your own risk!
 * 
 * License: MIT https://github.com/oxycon/ProjectApollo/blob/master/LICENSE.txt
 * For more information see: https://github.com/oxycon/ProjectApollo
 */

// SHTC3 I2C Temperature, Humidity Sensor

#ifndef SHTC3_H
#define SHTC3_H

#include <Adafruit_SHTC3.h>
#include "Sensor.h"


class Shtc3 : public Sensor {
public:
  bool begin(uint8_t i2cAddr = SHTC3_DEFAULT_ADDR);
  void run();
  const char* getTypeName() { return FS("SHTC3"); };
  size_t getSensorJson(char* buffer, size_t bSize=1<<30);
  size_t getDataJson(char* buffer, size_t bSize=1<<30);
  size_t getDataString(char* buffer, const char* fmt, size_t bSize=1<<30);
  virtual bool hasTemperature() { return true; }
  virtual bool hasHumidity() { return true; }

protected:
  Adafruit_SHTC3 shtc3_;
  sensors_event_t humidity_event_;
  sensors_event_t temperature_event_;
};

#endif // SHTC3_H
