# Leezenflow Sensor

Hardware:

- [ATOM LITE ESP32 DEV KIT](https://www.digikey.de/de/products/detail/m5stack-technology-co-ltd/C008/12088545)
- [1 TO 3 HUB GROVE EXPANSION UNIT](https://www.digikey.de/de/products/detail/m5stack-technology-co-ltd/U006/12088551)
- [ENV III UNIT WITH TEMPERATURE HU](https://www.digikey.de/de/products/detail/m5stack-technology-co-ltd/U001-C/14672141)
- [VOLTMETER UNIT ADS1115](https://www.digikey.de/de/products/detail/m5stack-technology-co-ltd/U087/13545174)

Software:
This Repo

## Usage
Connect the ATOM Liste to a USB Port and Connect to the Serial Port.
It will output the values every 2 seconds like this:

```
2160,40,100182,1221
```
The values mean:
- first value: temperature in Celsius * 10
- second value: humidity in percent
- third value: air pressure in Pa
- fourth value: battery current in mV

