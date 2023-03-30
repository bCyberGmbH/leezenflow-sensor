#include <M5Unified.h>
#include <M5_ENV.h>
#include <M5_ADS1115.h>

SHT3X sht30;
QMP6988 qmp6988;
ADS1115 voltmeter;

float tmp = 0.0;
float hum = 0.0;
float pressure = 0.0;
int voltage_value = 0;

void setup()
{
  // M5.begin(false, true, true, true);  // Init M5AtomS3Lite. 初始化M5AtomS3Lite
  M5.begin();
  Wire.begin();
  qmp6988.init();
  voltmeter.setMode(SINGLESHOT);
  voltmeter.setRate(RATE_128);
  voltmeter.setGain(PAG_512);
  Serial.println(F("Hello from a bCyber Sensor. Setup: Done!"));
}

void loop()
{
  pressure = qmp6988.calcPressure();
  if (sht30.get() == 0)
  {
    tmp = sht30.cTemp;
    hum = sht30.humidity;
  }
  else
  {
    tmp = 0, hum = 0;
  }
  Serial.printf(
      "Temp: %2.1f  \r\nHumi: %2.0f%%  \r\nPressure:%2.0fPa\r\n---\n", tmp,
      hum, pressure);

  voltmeter.getValue();
  voltage_value = voltmeter.adc_raw * voltmeter.resolution * voltmeter.calibration_factor;
  // normalize to positive voltage
  if (voltage_value < 0) voltage_value = voltage_value * -1;
  Serial.printf("Voltage Value: %1.2fV \n", voltage_value / 1000.0);
  delay(2000);
}