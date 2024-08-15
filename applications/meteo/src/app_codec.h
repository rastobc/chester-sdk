#ifndef CODEC_H_
#define CODEC_H_

/* This file has been generated using the script gen-codec.py */

#ifdef __cplusplus
extern "C" {
#endif

#define CODEC_CLOUD_DECODER_HASH ((uint64_t)0xe8aec82e4ae372cc)
#define CODEC_CLOUD_ENCODER_HASH ((uint64_t)0x0000000000000000)

enum codec_key_e {
	CODEC_KEY_E_MESSAGE = 0,
	CODEC_KEY_E_MESSAGE__VERSION = 1,
	CODEC_KEY_E_MESSAGE__SEQUENCE = 2,
	CODEC_KEY_E_MESSAGE__TIMESTAMP = 3,
	CODEC_KEY_E_SYSTEM = 4,
	CODEC_KEY_E_SYSTEM__UPTIME = 5,
	CODEC_KEY_E_SYSTEM__VOLTAGE_LOAD = 6,
	CODEC_KEY_E_SYSTEM__VOLTAGE_REST = 7,
	CODEC_KEY_E_SYSTEM__CURRENT_LOAD = 8,
	CODEC_KEY_E_ATTRIBUTE = 9,
	CODEC_KEY_E_ATTRIBUTE__VENDOR_NAME = 10,
	CODEC_KEY_E_ATTRIBUTE__PRODUCT_NAME = 11,
	CODEC_KEY_E_ATTRIBUTE__HW_VARIANT = 12,
	CODEC_KEY_E_ATTRIBUTE__HW_REVISION = 13,
	CODEC_KEY_E_ATTRIBUTE__FW_VERSION = 14,
	CODEC_KEY_E_ATTRIBUTE__SERIAL_NUMBER = 15,
	CODEC_KEY_E_NETWORK = 16,
	CODEC_KEY_E_NETWORK__PARAMETER = 17,
	CODEC_KEY_E_NETWORK__PARAMETER__EEST = 18,
	CODEC_KEY_E_NETWORK__PARAMETER__ECL = 19,
	CODEC_KEY_E_NETWORK__PARAMETER__RSRP = 20,
	CODEC_KEY_E_NETWORK__PARAMETER__RSRQ = 21,
	CODEC_KEY_E_NETWORK__PARAMETER__SNR = 22,
	CODEC_KEY_E_NETWORK__PARAMETER__PLMN = 23,
	CODEC_KEY_E_NETWORK__PARAMETER__CID = 24,
	CODEC_KEY_E_NETWORK__PARAMETER__BAND = 25,
	CODEC_KEY_E_NETWORK__PARAMETER__EARFCN = 26,
	CODEC_KEY_E_THERMOMETER = 27,
	CODEC_KEY_E_THERMOMETER__TEMPERATURE = 28,
	CODEC_KEY_E_ACCELEROMETER = 29,
	CODEC_KEY_E_ACCELEROMETER__ACCELERATION_X = 30,
	CODEC_KEY_E_ACCELEROMETER__ACCELERATION_Y = 31,
	CODEC_KEY_E_ACCELEROMETER__ACCELERATION_Z = 32,
	CODEC_KEY_E_ACCELEROMETER__ORIENTATION = 33,
	CODEC_KEY_E_TAMPER = 34,
	CODEC_KEY_E_TAMPER__STATE = 35,
	CODEC_KEY_E_TAMPER__EVENTS = 36,
	CODEC_KEY_E_BACKUP = 37,
	CODEC_KEY_E_BACKUP__LINE_VOLTAGE = 38,
	CODEC_KEY_E_BACKUP__BATT_VOLTAGE = 39,
	CODEC_KEY_E_BACKUP__STATE = 40,
	CODEC_KEY_E_BACKUP__EVENTS = 41,
	CODEC_KEY_E_W1_THERMOMETERS = 42,
	CODEC_KEY_E_W1_THERMOMETERS__SERIAL_NUMBER = 43,
	CODEC_KEY_E_W1_THERMOMETERS__MEASUREMENTS = 44,
	CODEC_KEY_E_BAROMETER = 45,
	CODEC_KEY_E_BAROMETER__PRESSURE = 46,
	CODEC_KEY_E_BAROMETER__PRESSURE__MEASUREMENTS = 47,
	CODEC_KEY_E_HYGROMETER = 48,
	CODEC_KEY_E_HYGROMETER__TEMPERATURE = 49,
	CODEC_KEY_E_HYGROMETER__TEMPERATURE__EVENTS = 50,
	CODEC_KEY_E_HYGROMETER__TEMPERATURE__MEASUREMENTS = 51,
	CODEC_KEY_E_HYGROMETER__HUMIDITY = 52,
	CODEC_KEY_E_HYGROMETER__HUMIDITY__MEASUREMENTS = 53,
	CODEC_KEY_E_SOIL_SENSORS = 54,
	CODEC_KEY_E_SOIL_SENSORS__SERIAL_NUMBER = 55,
	CODEC_KEY_E_SOIL_SENSORS__TEMPERATURE = 56,
	CODEC_KEY_E_SOIL_SENSORS__TEMPERATURE__MEASUREMENTS = 57,
	CODEC_KEY_E_SOIL_SENSORS__MOISTURE = 58,
	CODEC_KEY_E_SOIL_SENSORS__MOISTURE__MEASUREMENTS = 59,
	CODEC_KEY_E_BLE_TAGS = 60,
	CODEC_KEY_E_BLE_TAGS__ADDR = 61,
	CODEC_KEY_E_BLE_TAGS__RSSI = 62,
	CODEC_KEY_E_BLE_TAGS__VOLTAGE = 63,
	CODEC_KEY_E_BLE_TAGS__TEMPERATURE = 64,
	CODEC_KEY_E_BLE_TAGS__TEMPERATURE__MEASUREMENTS = 65,
	CODEC_KEY_E_BLE_TAGS__HUMIDITY = 66,
	CODEC_KEY_E_BLE_TAGS__HUMIDITY__MEASUREMENTS = 67,
	CODEC_KEY_E_WEATHER_STATION = 68,
	CODEC_KEY_E_WEATHER_STATION__WIND_SPEED = 69,
	CODEC_KEY_E_WEATHER_STATION__WIND_SPEED__MEASUREMENTS = 70,
	CODEC_KEY_E_WEATHER_STATION__WIND_DIRECTION = 71,
	CODEC_KEY_E_WEATHER_STATION__WIND_DIRECTION__MEASUREMENTS = 72,
	CODEC_KEY_E_WEATHER_STATION__RAINFALL = 73,
	CODEC_KEY_E_WEATHER_STATION__RAINFALL__MEASUREMENTS = 74,
	CODEC_KEY_E_LAMBRECHT_WEATHER_STATION = 75,
	CODEC_KEY_E_LAMBRECHT_WEATHER_STATION__WIND_SPEED = 76,
	CODEC_KEY_E_LAMBRECHT_WEATHER_STATION__WIND_SPEED__MEASUREMENTS = 77,
	CODEC_KEY_E_LAMBRECHT_WEATHER_STATION__WIND_DIRECTION = 78,
	CODEC_KEY_E_LAMBRECHT_WEATHER_STATION__WIND_DIRECTION__MEASUREMENTS = 79,
	CODEC_KEY_E_LAMBRECHT_WEATHER_STATION__TEMPERATURE = 80,
	CODEC_KEY_E_LAMBRECHT_WEATHER_STATION__TEMPERATURE__MEASUREMENTS = 81,
	CODEC_KEY_E_LAMBRECHT_WEATHER_STATION__HUMIDITY = 82,
	CODEC_KEY_E_LAMBRECHT_WEATHER_STATION__HUMIDITY__MEASUREMENTS = 83,
	CODEC_KEY_E_LAMBRECHT_WEATHER_STATION__DEW_POINT = 84,
	CODEC_KEY_E_LAMBRECHT_WEATHER_STATION__DEW_POINT__MEASUREMENTS = 85,
	CODEC_KEY_E_LAMBRECHT_WEATHER_STATION__PRESSURE = 86,
	CODEC_KEY_E_LAMBRECHT_WEATHER_STATION__PRESSURE__MEASUREMENTS = 87,
	CODEC_KEY_E_LAMBRECHT_WEATHER_STATION__RAINFALL = 88,
	CODEC_KEY_E_LAMBRECHT_WEATHER_STATION__RAINFALL__MEASUREMENTS = 89,
	CODEC_KEY_E_LAMBRECHT_WEATHER_STATION__RAINFALL_INTENSITY = 90,
	CODEC_KEY_E_LAMBRECHT_WEATHER_STATION__RAINFALL_INTENSITY__MEASUREMENTS = 91,
	CODEC_KEY_E_LAMBRECHT_WEATHER_STATION__RAINFALL_TOTAL = 92,
	CODEC_KEY_E_LAMBRECHT_WEATHER_STATION__ILLUMINANCE = 93,
	CODEC_KEY_E_LAMBRECHT_WEATHER_STATION__ILLUMINANCE__MEASUREMENTS = 94,
	CODEC_KEY_E_PYRANOMETER = 95,
	CODEC_KEY_E_PYRANOMETER__IRRADIANCE = 96,
	CODEC_KEY_E_PYRANOMETER__IRRADIANCE__MEASUREMENTS = 97,
};

#define CODEC_CLOUD_OPTIONS_STATIC(_name) \
	static const uint8_t _name##_cloud_decoder[] = CLOUD_DECODER_BUFFER; \
	static struct ctr_cloud_options _name = { \
		.decoder_hash = CODEC_CLOUD_DECODER_HASH, \
		.encoder_hash = CODEC_CLOUD_ENCODER_HASH, \
		.decoder_buf = _name##_cloud_decoder, \
		.decoder_len = 2765, \
		.encoder_buf = NULL, \
		.encoder_len = 0, \
}

#define CLOUD_DECODER_BUFFER { \
	0xa4, 0x67, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6f, \
	0x6e, 0x02, 0x64, 0x74, 0x79, 0x70, 0x65, 0x67, \
	0x64, 0x65, 0x63, 0x6f, 0x64, 0x65, 0x72, 0x64, \
	0x6e, 0x61, 0x6d, 0x65, 0x78, 0x1f, 0x63, 0x6f, \
	0x6d, 0x2e, 0x68, 0x61, 0x72, 0x64, 0x77, 0x61, \
	0x72, 0x69, 0x6f, 0x2e, 0x63, 0x68, 0x65, 0x73, \
	0x74, 0x65, 0x72, 0x2e, 0x61, 0x70, 0x70, 0x2e, \
	0x6d, 0x65, 0x74, 0x65, 0x6f, 0x66, 0x73, 0x63, \
	0x68, 0x65, 0x6d, 0x61, 0x90, 0xa1, 0x67, 0x6d, \
	0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x83, 0xa1, \
	0x67, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, \
	0xf6, 0xa1, 0x68, 0x73, 0x65, 0x71, 0x75, 0x65, \
	0x6e, 0x63, 0x65, 0xf6, 0xa1, 0x69, 0x74, 0x69, \
	0x6d, 0x65, 0x73, 0x74, 0x61, 0x6d, 0x70, 0xf6, \
	0xa1, 0x66, 0x73, 0x79, 0x73, 0x74, 0x65, 0x6d, \
	0x84, 0xa1, 0x66, 0x75, 0x70, 0x74, 0x69, 0x6d, \
	0x65, 0xf6, 0xa1, 0x6c, 0x76, 0x6f, 0x6c, 0x74, \
	0x61, 0x67, 0x65, 0x5f, 0x6c, 0x6f, 0x61, 0x64, \
	0x82, 0xa1, 0x64, 0x24, 0x64, 0x69, 0x76, 0x19, \
	0x03, 0xe8, 0xa1, 0x64, 0x24, 0x66, 0x70, 0x70, \
	0x02, 0xa1, 0x6c, 0x76, 0x6f, 0x6c, 0x74, 0x61, \
	0x67, 0x65, 0x5f, 0x72, 0x65, 0x73, 0x74, 0x82, \
	0xa1, 0x64, 0x24, 0x64, 0x69, 0x76, 0x19, 0x03, \
	0xe8, 0xa1, 0x64, 0x24, 0x66, 0x70, 0x70, 0x02, \
	0xa1, 0x6c, 0x63, 0x75, 0x72, 0x72, 0x65, 0x6e, \
	0x74, 0x5f, 0x6c, 0x6f, 0x61, 0x64, 0xf6, 0xa1, \
	0x69, 0x61, 0x74, 0x74, 0x72, 0x69, 0x62, 0x75, \
	0x74, 0x65, 0x86, 0xa1, 0x6b, 0x76, 0x65, 0x6e, \
	0x64, 0x6f, 0x72, 0x5f, 0x6e, 0x61, 0x6d, 0x65, \
	0xf6, 0xa1, 0x6c, 0x70, 0x72, 0x6f, 0x64, 0x75, \
	0x63, 0x74, 0x5f, 0x6e, 0x61, 0x6d, 0x65, 0xf6, \
	0xa1, 0x6a, 0x68, 0x77, 0x5f, 0x76, 0x61, 0x72, \
	0x69, 0x61, 0x6e, 0x74, 0xf6, 0xa1, 0x6b, 0x68, \
	0x77, 0x5f, 0x72, 0x65, 0x76, 0x69, 0x73, 0x69, \
	0x6f, 0x6e, 0xf6, 0xa1, 0x6a, 0x66, 0x77, 0x5f, \
	0x76, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0xf6, \
	0xa1, 0x6d, 0x73, 0x65, 0x72, 0x69, 0x61, 0x6c, \
	0x5f, 0x6e, 0x75, 0x6d, 0x62, 0x65, 0x72, 0xf6, \
	0xa1, 0x67, 0x6e, 0x65, 0x74, 0x77, 0x6f, 0x72, \
	0x6b, 0x81, 0xa1, 0x69, 0x70, 0x61, 0x72, 0x61, \
	0x6d, 0x65, 0x74, 0x65, 0x72, 0x89, 0xa1, 0x64, \
	0x65, 0x65, 0x73, 0x74, 0xf6, 0xa1, 0x63, 0x65, \
	0x63, 0x6c, 0xf6, 0xa1, 0x64, 0x72, 0x73, 0x72, \
	0x70, 0xf6, 0xa1, 0x64, 0x72, 0x73, 0x72, 0x71, \
	0xf6, 0xa1, 0x63, 0x73, 0x6e, 0x72, 0xf6, 0xa1, \
	0x64, 0x70, 0x6c, 0x6d, 0x6e, 0xf6, 0xa1, 0x63, \
	0x63, 0x69, 0x64, 0xf6, 0xa1, 0x64, 0x62, 0x61, \
	0x6e, 0x64, 0xf6, 0xa1, 0x66, 0x65, 0x61, 0x72, \
	0x66, 0x63, 0x6e, 0xf6, 0xa1, 0x6b, 0x74, 0x68, \
	0x65, 0x72, 0x6d, 0x6f, 0x6d, 0x65, 0x74, 0x65, \
	0x72, 0x81, 0xa1, 0x6b, 0x74, 0x65, 0x6d, 0x70, \
	0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x82, \
	0xa1, 0x64, 0x24, 0x64, 0x69, 0x76, 0x18, 0x64, \
	0xa1, 0x64, 0x24, 0x66, 0x70, 0x70, 0x02, 0xa1, \
	0x6d, 0x61, 0x63, 0x63, 0x65, 0x6c, 0x65, 0x72, \
	0x6f, 0x6d, 0x65, 0x74, 0x65, 0x72, 0x84, 0xa1, \
	0x6e, 0x61, 0x63, 0x63, 0x65, 0x6c, 0x65, 0x72, \
	0x61, 0x74, 0x69, 0x6f, 0x6e, 0x5f, 0x78, 0x82, \
	0xa1, 0x64, 0x24, 0x64, 0x69, 0x76, 0x19, 0x03, \
	0xe8, 0xa1, 0x64, 0x24, 0x66, 0x70, 0x70, 0x02, \
	0xa1, 0x6e, 0x61, 0x63, 0x63, 0x65, 0x6c, 0x65, \
	0x72, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x5f, 0x79, \
	0x82, 0xa1, 0x64, 0x24, 0x64, 0x69, 0x76, 0x19, \
	0x03, 0xe8, 0xa1, 0x64, 0x24, 0x66, 0x70, 0x70, \
	0x02, 0xa1, 0x6e, 0x61, 0x63, 0x63, 0x65, 0x6c, \
	0x65, 0x72, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x5f, \
	0x7a, 0x82, 0xa1, 0x64, 0x24, 0x64, 0x69, 0x76, \
	0x19, 0x03, 0xe8, 0xa1, 0x64, 0x24, 0x66, 0x70, \
	0x70, 0x02, 0xa1, 0x6b, 0x6f, 0x72, 0x69, 0x65, \
	0x6e, 0x74, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0xf6, \
	0xa1, 0x66, 0x74, 0x61, 0x6d, 0x70, 0x65, 0x72, \
	0x82, 0xa1, 0x65, 0x73, 0x74, 0x61, 0x74, 0x65, \
	0x81, 0xa1, 0x65, 0x24, 0x65, 0x6e, 0x75, 0x6d, \
	0x82, 0x68, 0x69, 0x6e, 0x61, 0x63, 0x74, 0x69, \
	0x76, 0x65, 0x66, 0x61, 0x63, 0x74, 0x69, 0x76, \
	0x65, 0xa1, 0x66, 0x65, 0x76, 0x65, 0x6e, 0x74, \
	0x73, 0x82, 0xa1, 0x64, 0x24, 0x6b, 0x65, 0x79, \
	0x66, 0x65, 0x76, 0x65, 0x6e, 0x74, 0x73, 0xa1, \
	0x64, 0x24, 0x74, 0x73, 0x6f, 0x81, 0xa1, 0x64, \
	0x74, 0x79, 0x70, 0x65, 0x81, 0xa1, 0x65, 0x24, \
	0x65, 0x6e, 0x75, 0x6d, 0x82, 0x6b, 0x64, 0x65, \
	0x61, 0x63, 0x74, 0x69, 0x76, 0x61, 0x74, 0x65, \
	0x64, 0x69, 0x61, 0x63, 0x74, 0x69, 0x76, 0x61, \
	0x74, 0x65, 0x64, 0xa1, 0x66, 0x62, 0x61, 0x63, \
	0x6b, 0x75, 0x70, 0x84, 0xa1, 0x6c, 0x6c, 0x69, \
	0x6e, 0x65, 0x5f, 0x76, 0x6f, 0x6c, 0x74, 0x61, \
	0x67, 0x65, 0xf6, 0xa1, 0x6c, 0x62, 0x61, 0x74, \
	0x74, 0x5f, 0x76, 0x6f, 0x6c, 0x74, 0x61, 0x67, \
	0x65, 0xf6, 0xa1, 0x65, 0x73, 0x74, 0x61, 0x74, \
	0x65, 0x81, 0xa1, 0x65, 0x24, 0x65, 0x6e, 0x75, \
	0x6d, 0x82, 0x6c, 0x64, 0x69, 0x73, 0x63, 0x6f, \
	0x6e, 0x6e, 0x65, 0x63, 0x74, 0x65, 0x64, 0x69, \
	0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x65, \
	0x64, 0xa1, 0x66, 0x65, 0x76, 0x65, 0x6e, 0x74, \
	0x73, 0x82, 0xa1, 0x64, 0x24, 0x6b, 0x65, 0x79, \
	0x66, 0x65, 0x76, 0x65, 0x6e, 0x74, 0x73, 0xa1, \
	0x64, 0x24, 0x74, 0x73, 0x6f, 0x81, 0xa1, 0x64, \
	0x74, 0x79, 0x70, 0x65, 0x81, 0xa1, 0x65, 0x24, \
	0x65, 0x6e, 0x75, 0x6d, 0x82, 0x6c, 0x64, 0x69, \
	0x73, 0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, \
	0x65, 0x64, 0x69, 0x63, 0x6f, 0x6e, 0x6e, 0x65, \
	0x63, 0x74, 0x65, 0x64, 0xa1, 0x6f, 0x77, 0x31, \
	0x5f, 0x74, 0x68, 0x65, 0x72, 0x6d, 0x6f, 0x6d, \
	0x65, 0x74, 0x65, 0x72, 0x73, 0x82, 0xa1, 0x6d, \
	0x73, 0x65, 0x72, 0x69, 0x61, 0x6c, 0x5f, 0x6e, \
	0x75, 0x6d, 0x62, 0x65, 0x72, 0xf6, 0xa1, 0x6c, \
	0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, \
	0x65, 0x6e, 0x74, 0x73, 0x81, 0xa1, 0x64, 0x24, \
	0x74, 0x73, 0x70, 0x84, 0xa1, 0x63, 0x6d, 0x69, \
	0x6e, 0x82, 0xa1, 0x64, 0x24, 0x64, 0x69, 0x76, \
	0x18, 0x64, 0xa1, 0x64, 0x24, 0x66, 0x70, 0x70, \
	0x02, 0xa1, 0x63, 0x6d, 0x61, 0x78, 0x82, 0xa1, \
	0x64, 0x24, 0x64, 0x69, 0x76, 0x18, 0x64, 0xa1, \
	0x64, 0x24, 0x66, 0x70, 0x70, 0x02, 0xa1, 0x63, \
	0x61, 0x76, 0x67, 0x82, 0xa1, 0x64, 0x24, 0x64, \
	0x69, 0x76, 0x18, 0x64, 0xa1, 0x64, 0x24, 0x66, \
	0x70, 0x70, 0x02, 0xa1, 0x63, 0x6d, 0x64, 0x6e, \
	0x82, 0xa1, 0x64, 0x24, 0x64, 0x69, 0x76, 0x18, \
	0x64, 0xa1, 0x64, 0x24, 0x66, 0x70, 0x70, 0x02, \
	0xa1, 0x69, 0x62, 0x61, 0x72, 0x6f, 0x6d, 0x65, \
	0x74, 0x65, 0x72, 0x81, 0xa1, 0x68, 0x70, 0x72, \
	0x65, 0x73, 0x73, 0x75, 0x72, 0x65, 0x81, 0xa1, \
	0x6c, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, \
	0x6d, 0x65, 0x6e, 0x74, 0x73, 0x81, 0xa1, 0x64, \
	0x24, 0x74, 0x73, 0x70, 0x84, 0xa1, 0x63, 0x6d, \
	0x69, 0x6e, 0xf6, 0xa1, 0x63, 0x6d, 0x61, 0x78, \
	0xf6, 0xa1, 0x63, 0x61, 0x76, 0x67, 0xf6, 0xa1, \
	0x63, 0x6d, 0x64, 0x6e, 0xf6, 0xa1, 0x6a, 0x68, \
	0x79, 0x67, 0x72, 0x6f, 0x6d, 0x65, 0x74, 0x65, \
	0x72, 0x82, 0xa1, 0x6b, 0x74, 0x65, 0x6d, 0x70, \
	0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x82, \
	0xa1, 0x66, 0x65, 0x76, 0x65, 0x6e, 0x74, 0x73, \
	0x81, 0xa1, 0x64, 0x24, 0x74, 0x73, 0x6f, 0x81, \
	0xa1, 0x64, 0x74, 0x79, 0x70, 0x65, 0x81, 0xa1, \
	0x65, 0x24, 0x65, 0x6e, 0x75, 0x6d, 0x84, 0x72, \
	0x61, 0x6c, 0x61, 0x72, 0x6d, 0x5f, 0x68, 0x69, \
	0x5f, 0x61, 0x63, 0x74, 0x69, 0x76, 0x61, 0x74, \
	0x65, 0x64, 0x74, 0x61, 0x6c, 0x61, 0x72, 0x6d, \
	0x5f, 0x68, 0x69, 0x5f, 0x64, 0x65, 0x61, 0x63, \
	0x74, 0x69, 0x76, 0x61, 0x74, 0x65, 0x64, 0x72, \
	0x61, 0x6c, 0x61, 0x72, 0x6d, 0x5f, 0x6c, 0x6f, \
	0x5f, 0x61, 0x63, 0x74, 0x69, 0x76, 0x61, 0x74, \
	0x65, 0x64, 0x74, 0x61, 0x6c, 0x61, 0x72, 0x6d, \
	0x5f, 0x6c, 0x6f, 0x5f, 0x64, 0x65, 0x61, 0x63, \
	0x74, 0x69, 0x76, 0x61, 0x74, 0x65, 0x64, 0xa1, \
	0x6c, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, \
	0x6d, 0x65, 0x6e, 0x74, 0x73, 0x81, 0xa1, 0x64, \
	0x24, 0x74, 0x73, 0x70, 0x84, 0xa1, 0x63, 0x6d, \
	0x69, 0x6e, 0x82, 0xa1, 0x64, 0x24, 0x64, 0x69, \
	0x76, 0x18, 0x64, 0xa1, 0x64, 0x24, 0x66, 0x70, \
	0x70, 0x02, 0xa1, 0x63, 0x6d, 0x61, 0x78, 0x82, \
	0xa1, 0x64, 0x24, 0x64, 0x69, 0x76, 0x18, 0x64, \
	0xa1, 0x64, 0x24, 0x66, 0x70, 0x70, 0x02, 0xa1, \
	0x63, 0x61, 0x76, 0x67, 0x82, 0xa1, 0x64, 0x24, \
	0x64, 0x69, 0x76, 0x18, 0x64, 0xa1, 0x64, 0x24, \
	0x66, 0x70, 0x70, 0x02, 0xa1, 0x63, 0x6d, 0x64, \
	0x6e, 0x82, 0xa1, 0x64, 0x24, 0x64, 0x69, 0x76, \
	0x18, 0x64, 0xa1, 0x64, 0x24, 0x66, 0x70, 0x70, \
	0x02, 0xa1, 0x68, 0x68, 0x75, 0x6d, 0x69, 0x64, \
	0x69, 0x74, 0x79, 0x81, 0xa1, 0x6c, 0x6d, 0x65, \
	0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, \
	0x74, 0x73, 0x81, 0xa1, 0x64, 0x24, 0x74, 0x73, \
	0x70, 0x84, 0xa1, 0x63, 0x6d, 0x69, 0x6e, 0x82, \
	0xa1, 0x64, 0x24, 0x64, 0x69, 0x76, 0x18, 0x64, \
	0xa1, 0x64, 0x24, 0x66, 0x70, 0x70, 0x02, 0xa1, \
	0x63, 0x6d, 0x61, 0x78, 0x82, 0xa1, 0x64, 0x24, \
	0x64, 0x69, 0x76, 0x18, 0x64, 0xa1, 0x64, 0x24, \
	0x66, 0x70, 0x70, 0x02, 0xa1, 0x63, 0x61, 0x76, \
	0x67, 0x82, 0xa1, 0x64, 0x24, 0x64, 0x69, 0x76, \
	0x18, 0x64, 0xa1, 0x64, 0x24, 0x66, 0x70, 0x70, \
	0x02, 0xa1, 0x63, 0x6d, 0x64, 0x6e, 0x82, 0xa1, \
	0x64, 0x24, 0x64, 0x69, 0x76, 0x18, 0x64, 0xa1, \
	0x64, 0x24, 0x66, 0x70, 0x70, 0x02, 0xa1, 0x6c, \
	0x73, 0x6f, 0x69, 0x6c, 0x5f, 0x73, 0x65, 0x6e, \
	0x73, 0x6f, 0x72, 0x73, 0x83, 0xa1, 0x6d, 0x73, \
	0x65, 0x72, 0x69, 0x61, 0x6c, 0x5f, 0x6e, 0x75, \
	0x6d, 0x62, 0x65, 0x72, 0xf6, 0xa1, 0x6b, 0x74, \
	0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, \
	0x72, 0x65, 0x81, 0xa1, 0x6c, 0x6d, 0x65, 0x61, \
	0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, \
	0x73, 0x81, 0xa1, 0x64, 0x24, 0x74, 0x73, 0x70, \
	0x84, 0xa1, 0x63, 0x6d, 0x69, 0x6e, 0x82, 0xa1, \
	0x64, 0x24, 0x64, 0x69, 0x76, 0x18, 0x64, 0xa1, \
	0x64, 0x24, 0x66, 0x70, 0x70, 0x02, 0xa1, 0x63, \
	0x6d, 0x61, 0x78, 0x82, 0xa1, 0x64, 0x24, 0x64, \
	0x69, 0x76, 0x18, 0x64, 0xa1, 0x64, 0x24, 0x66, \
	0x70, 0x70, 0x02, 0xa1, 0x63, 0x61, 0x76, 0x67, \
	0x82, 0xa1, 0x64, 0x24, 0x64, 0x69, 0x76, 0x18, \
	0x64, 0xa1, 0x64, 0x24, 0x66, 0x70, 0x70, 0x02, \
	0xa1, 0x63, 0x6d, 0x64, 0x6e, 0x82, 0xa1, 0x64, \
	0x24, 0x64, 0x69, 0x76, 0x18, 0x64, 0xa1, 0x64, \
	0x24, 0x66, 0x70, 0x70, 0x02, 0xa1, 0x68, 0x6d, \
	0x6f, 0x69, 0x73, 0x74, 0x75, 0x72, 0x65, 0x81, \
	0xa1, 0x6c, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, \
	0x65, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x81, 0xa1, \
	0x64, 0x24, 0x74, 0x73, 0x70, 0x84, 0xa1, 0x63, \
	0x6d, 0x69, 0x6e, 0xf6, 0xa1, 0x63, 0x6d, 0x61, \
	0x78, 0xf6, 0xa1, 0x63, 0x61, 0x76, 0x67, 0xf6, \
	0xa1, 0x63, 0x6d, 0x64, 0x6e, 0xf6, 0xa1, 0x68, \
	0x62, 0x6c, 0x65, 0x5f, 0x74, 0x61, 0x67, 0x73, \
	0x85, 0xa1, 0x64, 0x61, 0x64, 0x64, 0x72, 0xf6, \
	0xa1, 0x64, 0x72, 0x73, 0x73, 0x69, 0xf6, 0xa1, \
	0x67, 0x76, 0x6f, 0x6c, 0x74, 0x61, 0x67, 0x65, \
	0x82, 0xa1, 0x64, 0x24, 0x64, 0x69, 0x76, 0x18, \
	0x64, 0xa1, 0x64, 0x24, 0x66, 0x70, 0x70, 0x02, \
	0xa1, 0x6b, 0x74, 0x65, 0x6d, 0x70, 0x65, 0x72, \
	0x61, 0x74, 0x75, 0x72, 0x65, 0x81, 0xa1, 0x6c, \
	0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, \
	0x65, 0x6e, 0x74, 0x73, 0x81, 0xa1, 0x64, 0x24, \
	0x74, 0x73, 0x70, 0x84, 0xa1, 0x63, 0x6d, 0x69, \
	0x6e, 0x82, 0xa1, 0x64, 0x24, 0x64, 0x69, 0x76, \
	0x18, 0x64, 0xa1, 0x64, 0x24, 0x66, 0x70, 0x70, \
	0x02, 0xa1, 0x63, 0x6d, 0x61, 0x78, 0x82, 0xa1, \
	0x64, 0x24, 0x64, 0x69, 0x76, 0x18, 0x64, 0xa1, \
	0x64, 0x24, 0x66, 0x70, 0x70, 0x02, 0xa1, 0x63, \
	0x61, 0x76, 0x67, 0x82, 0xa1, 0x64, 0x24, 0x64, \
	0x69, 0x76, 0x18, 0x64, 0xa1, 0x64, 0x24, 0x66, \
	0x70, 0x70, 0x02, 0xa1, 0x63, 0x6d, 0x64, 0x6e, \
	0x82, 0xa1, 0x64, 0x24, 0x64, 0x69, 0x76, 0x18, \
	0x64, 0xa1, 0x64, 0x24, 0x66, 0x70, 0x70, 0x02, \
	0xa1, 0x68, 0x68, 0x75, 0x6d, 0x69, 0x64, 0x69, \
	0x74, 0x79, 0x81, 0xa1, 0x6c, 0x6d, 0x65, 0x61, \
	0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, \
	0x73, 0x81, 0xa1, 0x64, 0x24, 0x74, 0x73, 0x70, \
	0x84, 0xa1, 0x63, 0x6d, 0x69, 0x6e, 0x82, 0xa1, \
	0x64, 0x24, 0x64, 0x69, 0x76, 0x18, 0x64, 0xa1, \
	0x64, 0x24, 0x66, 0x70, 0x70, 0x02, 0xa1, 0x63, \
	0x6d, 0x61, 0x78, 0x82, 0xa1, 0x64, 0x24, 0x64, \
	0x69, 0x76, 0x18, 0x64, 0xa1, 0x64, 0x24, 0x66, \
	0x70, 0x70, 0x02, 0xa1, 0x63, 0x61, 0x76, 0x67, \
	0x82, 0xa1, 0x64, 0x24, 0x64, 0x69, 0x76, 0x18, \
	0x64, 0xa1, 0x64, 0x24, 0x66, 0x70, 0x70, 0x02, \
	0xa1, 0x63, 0x6d, 0x64, 0x6e, 0x82, 0xa1, 0x64, \
	0x24, 0x64, 0x69, 0x76, 0x18, 0x64, 0xa1, 0x64, \
	0x24, 0x66, 0x70, 0x70, 0x02, 0xa1, 0x6f, 0x77, \
	0x65, 0x61, 0x74, 0x68, 0x65, 0x72, 0x5f, 0x73, \
	0x74, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x83, 0xa1, \
	0x6a, 0x77, 0x69, 0x6e, 0x64, 0x5f, 0x73, 0x70, \
	0x65, 0x65, 0x64, 0x81, 0xa1, 0x6c, 0x6d, 0x65, \
	0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, \
	0x74, 0x73, 0x81, 0xa1, 0x64, 0x24, 0x74, 0x73, \
	0x70, 0x84, 0xa1, 0x63, 0x6d, 0x69, 0x6e, 0x82, \
	0xa1, 0x64, 0x24, 0x64, 0x69, 0x76, 0x18, 0x64, \
	0xa1, 0x64, 0x24, 0x66, 0x70, 0x70, 0x02, 0xa1, \
	0x63, 0x6d, 0x61, 0x78, 0x82, 0xa1, 0x64, 0x24, \
	0x64, 0x69, 0x76, 0x18, 0x64, 0xa1, 0x64, 0x24, \
	0x66, 0x70, 0x70, 0x02, 0xa1, 0x63, 0x61, 0x76, \
	0x67, 0x82, 0xa1, 0x64, 0x24, 0x64, 0x69, 0x76, \
	0x18, 0x64, 0xa1, 0x64, 0x24, 0x66, 0x70, 0x70, \
	0x02, 0xa1, 0x63, 0x6d, 0x64, 0x6e, 0x82, 0xa1, \
	0x64, 0x24, 0x64, 0x69, 0x76, 0x18, 0x64, 0xa1, \
	0x64, 0x24, 0x66, 0x70, 0x70, 0x02, 0xa1, 0x6e, \
	0x77, 0x69, 0x6e, 0x64, 0x5f, 0x64, 0x69, 0x72, \
	0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x81, 0xa1, \
	0x6c, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, \
	0x6d, 0x65, 0x6e, 0x74, 0x73, 0x81, 0xa1, 0x64, \
	0x24, 0x74, 0x73, 0x70, 0x81, 0xa1, 0x65, 0x76, \
	0x61, 0x6c, 0x75, 0x65, 0xf6, 0xa1, 0x68, 0x72, \
	0x61, 0x69, 0x6e, 0x66, 0x61, 0x6c, 0x6c, 0x81, \
	0xa1, 0x6c, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, \
	0x65, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x81, 0xa1, \
	0x64, 0x24, 0x74, 0x73, 0x70, 0x81, 0xa1, 0x65, \
	0x76, 0x61, 0x6c, 0x75, 0x65, 0x82, 0xa1, 0x64, \
	0x24, 0x64, 0x69, 0x76, 0x18, 0x64, 0xa1, 0x64, \
	0x24, 0x66, 0x70, 0x70, 0x02, 0xa1, 0x78, 0x19, \
	0x6c, 0x61, 0x6d, 0x62, 0x72, 0x65, 0x63, 0x68, \
	0x74, 0x5f, 0x77, 0x65, 0x61, 0x74, 0x68, 0x65, \
	0x72, 0x5f, 0x73, 0x74, 0x61, 0x74, 0x69, 0x6f, \
	0x6e, 0x8a, 0xa1, 0x6a, 0x77, 0x69, 0x6e, 0x64, \
	0x5f, 0x73, 0x70, 0x65, 0x65, 0x64, 0x81, 0xa1, \
	0x6c, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, \
	0x6d, 0x65, 0x6e, 0x74, 0x73, 0x81, 0xa1, 0x64, \
	0x24, 0x74, 0x73, 0x70, 0x81, 0xa1, 0x65, 0x76, \
	0x61, 0x6c, 0x75, 0x65, 0x82, 0xa1, 0x64, 0x24, \
	0x64, 0x69, 0x76, 0x18, 0x64, 0xa1, 0x64, 0x24, \
	0x66, 0x70, 0x70, 0x02, 0xa1, 0x6e, 0x77, 0x69, \
	0x6e, 0x64, 0x5f, 0x64, 0x69, 0x72, 0x65, 0x63, \
	0x74, 0x69, 0x6f, 0x6e, 0x81, 0xa1, 0x6c, 0x6d, \
	0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, \
	0x6e, 0x74, 0x73, 0x81, 0xa1, 0x64, 0x24, 0x74, \
	0x73, 0x70, 0x81, 0xa1, 0x65, 0x76, 0x61, 0x6c, \
	0x75, 0x65, 0x82, 0xa1, 0x64, 0x24, 0x64, 0x69, \
	0x76, 0x18, 0x64, 0xa1, 0x64, 0x24, 0x66, 0x70, \
	0x70, 0x02, 0xa1, 0x6b, 0x74, 0x65, 0x6d, 0x70, \
	0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x81, \
	0xa1, 0x6c, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, \
	0x65, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x81, 0xa1, \
	0x64, 0x24, 0x74, 0x73, 0x70, 0x81, 0xa1, 0x65, \
	0x76, 0x61, 0x6c, 0x75, 0x65, 0x82, 0xa1, 0x64, \
	0x24, 0x64, 0x69, 0x76, 0x18, 0x64, 0xa1, 0x64, \
	0x24, 0x66, 0x70, 0x70, 0x02, 0xa1, 0x68, 0x68, \
	0x75, 0x6d, 0x69, 0x64, 0x69, 0x74, 0x79, 0x81, \
	0xa1, 0x6c, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, \
	0x65, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x81, 0xa1, \
	0x64, 0x24, 0x74, 0x73, 0x70, 0x81, 0xa1, 0x65, \
	0x76, 0x61, 0x6c, 0x75, 0x65, 0x82, 0xa1, 0x64, \
	0x24, 0x64, 0x69, 0x76, 0x18, 0x64, 0xa1, 0x64, \
	0x24, 0x66, 0x70, 0x70, 0x02, 0xa1, 0x69, 0x64, \
	0x65, 0x77, 0x5f, 0x70, 0x6f, 0x69, 0x6e, 0x74, \
	0x81, 0xa1, 0x6c, 0x6d, 0x65, 0x61, 0x73, 0x75, \
	0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x81, \
	0xa1, 0x64, 0x24, 0x74, 0x73, 0x70, 0x81, 0xa1, \
	0x65, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x82, 0xa1, \
	0x64, 0x24, 0x64, 0x69, 0x76, 0x18, 0x64, 0xa1, \
	0x64, 0x24, 0x66, 0x70, 0x70, 0x02, 0xa1, 0x68, \
	0x70, 0x72, 0x65, 0x73, 0x73, 0x75, 0x72, 0x65, \
	0x81, 0xa1, 0x6c, 0x6d, 0x65, 0x61, 0x73, 0x75, \
	0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x81, \
	0xa1, 0x64, 0x24, 0x74, 0x73, 0x70, 0x81, 0xa1, \
	0x65, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x82, 0xa1, \
	0x64, 0x24, 0x64, 0x69, 0x76, 0x18, 0x64, 0xa1, \
	0x64, 0x24, 0x66, 0x70, 0x70, 0x02, 0xa1, 0x68, \
	0x72, 0x61, 0x69, 0x6e, 0x66, 0x61, 0x6c, 0x6c, \
	0x81, 0xa1, 0x6c, 0x6d, 0x65, 0x61, 0x73, 0x75, \
	0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x73, 0x81, \
	0xa1, 0x64, 0x24, 0x74, 0x73, 0x70, 0x81, 0xa1, \
	0x65, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x82, 0xa1, \
	0x64, 0x24, 0x64, 0x69, 0x76, 0x18, 0x64, 0xa1, \
	0x64, 0x24, 0x66, 0x70, 0x70, 0x02, 0xa1, 0x72, \
	0x72, 0x61, 0x69, 0x6e, 0x66, 0x61, 0x6c, 0x6c, \
	0x5f, 0x69, 0x6e, 0x74, 0x65, 0x6e, 0x73, 0x69, \
	0x74, 0x79, 0x81, 0xa1, 0x6c, 0x6d, 0x65, 0x61, \
	0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, \
	0x73, 0x81, 0xa1, 0x64, 0x24, 0x74, 0x73, 0x70, \
	0x81, 0xa1, 0x65, 0x76, 0x61, 0x6c, 0x75, 0x65, \
	0x82, 0xa1, 0x64, 0x24, 0x64, 0x69, 0x76, 0x18, \
	0x64, 0xa1, 0x64, 0x24, 0x66, 0x70, 0x70, 0x02, \
	0xa1, 0x6e, 0x72, 0x61, 0x69, 0x6e, 0x66, 0x61, \
	0x6c, 0x6c, 0x5f, 0x74, 0x6f, 0x74, 0x61, 0x6c, \
	0xf6, 0xa1, 0x6b, 0x69, 0x6c, 0x6c, 0x75, 0x6d, \
	0x69, 0x6e, 0x61, 0x6e, 0x63, 0x65, 0x81, 0xa1, \
	0x6c, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, \
	0x6d, 0x65, 0x6e, 0x74, 0x73, 0x81, 0xa1, 0x64, \
	0x24, 0x74, 0x73, 0x70, 0x81, 0xa1, 0x65, 0x76, \
	0x61, 0x6c, 0x75, 0x65, 0x82, 0xa1, 0x64, 0x24, \
	0x64, 0x69, 0x76, 0x18, 0x64, 0xa1, 0x64, 0x24, \
	0x66, 0x70, 0x70, 0x02, 0xa1, 0x6b, 0x70, 0x79, \
	0x72, 0x61, 0x6e, 0x6f, 0x6d, 0x65, 0x74, 0x65, \
	0x72, 0x81, 0xa1, 0x6a, 0x69, 0x72, 0x72, 0x61, \
	0x64, 0x69, 0x61, 0x6e, 0x63, 0x65, 0x81, 0xa1, \
	0x6c, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, \
	0x6d, 0x65, 0x6e, 0x74, 0x73, 0x81, 0xa1, 0x64, \
	0x24, 0x74, 0x73, 0x70, 0x84, 0xa1, 0x63, 0x6d, \
	0x69, 0x6e, 0xf6, 0xa1, 0x63, 0x6d, 0x61, 0x78, \
	0xf6, 0xa1, 0x63, 0x61, 0x76, 0x67, 0xf6, 0xa1, \
	0x63, 0x6d, 0x64, 0x6e, 0xf6, \
}

#ifdef __cplusplus
}
#endif

#endif /* CODEC_H_ */
