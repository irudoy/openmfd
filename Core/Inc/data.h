#ifndef INC_MFD_DATA_H_
#define INC_MFD_DATA_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"

/**
 * # CANsult CAN Protocol
 *
 * ## Stream
 *
 * |  ID   | DLC |     Byte 0      |    Byte 1    |     Byte 2      |    Byte 3    |    Byte 4    |    Byte 5    |     Byte 6     |         Byte 7          |
 * |-------|-----|-----------------|--------------|-----------------|--------------|--------------|--------------|----------------|-------------------------|
 * | 0x666 |   8 | BATTERY_VOLTAGE | COOLANT_TEMP | IGNITION_TIMING | LEFT_O2      | TPS          | AAC_VALVE    | LEFT_AF_ALPHA  | LEFT_AF_ALPHA_SELFLEARN |
 * | 0x667 |   8 | VEHICLE_SPEED   | TACH_MSB     | TACH_LSB        | INJ_TIME_MSB | INJ_TIME_LSB | LEFT_MAF_MSB | LEFT_MAF_LSB   |                         |
 * | 0x668 |   8 | BIT_1           | BIT_2        | DEVICE_VOLTAGE  |              |              |              | First DTC Code | Heartbeat               |
 *
 * BIT_1:
 * BITMASK_NEUTRAL_SW 0b00000100
 * BITMASK_START_SIGNAL 0b00000010
 * BITMASK_THROTTLE_CLOSED 0b00000001
 *
 * BIT_2:
 * BITMASK_FUEL_PUMP_RELAY 0b01000000
 * BITMASK_VTC_SOLENOID 0b00100000
 * */

#define MFD_DATASOURCES_SIZE 32

// CANSult
#define MFD_DATA_BATT_VOLTAGE              0
#define MFD_DATA_CLT_TEMP                  1
#define MFD_DATA_IGN_TIMING                2
#define MFD_DATA_O2_LEFT                   3
#define MFD_DATA_TPS                       4
#define MFD_DATA_AAC_VALVE                 5
#define MFD_DATA_AF_ALPHA_L                6
#define MFD_DATA_AF_ALPHA_L_SL             7
#define MFD_DATA_VEHICLE_SPEED             8
#define MFD_DATA_ENGINE_SPEED              9
#define MFD_DATA_INJ_TIME                  10
#define MFD_DATA_LEFT_MAF                  11
#define MFD_DATA_CANSULT_VOLTAGE           12
#define MFD_DATA_FIRST_DTC_CODE            13
#define MFD_DATA_NEUTRAL_SW_STATE          14
#define MFD_DATA_START_SIGNAL_STATE        15
#define MFD_DATA_THROTTLE_CLOSED_STATE     16
#define MFD_DATA_FUEL_PUMP_RELAY_STATE     17
#define MFD_DATA_VTC_SOLENOID_STATE        18

// Other
#define MFD_DATA_BOOST_PRESSURE            19

typedef struct
{
  int value;
  int peakValue;
  int min;
  int max;
  char name[10];
  int8_t DEBUG_modifier;
} MFD_DataSourceTypeDef;

extern MFD_DataSourceTypeDef MFD_DataSourcesAll[MFD_DATASOURCES_SIZE];

void MFD_DataInit(void);
MFD_DataSourceTypeDef* MFD_DataGetEntry(uint8_t id);

#ifdef __cplusplus
}
#endif

#endif /* INC_MFD_DATA_H_ */
