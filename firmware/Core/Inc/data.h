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

#define MFD_GAUGES_SIZE 32

typedef enum {
  MFD_Gauge_AFR,
  MFD_Gauge_BattVoltage,
  MFD_Gauge_CltTemp,
  MFD_Gauge_IgnTiming,
  MFD_Gauge_AACValve,
  MFD_Gauge_AFAlphaL,
  MFD_Gauge_AFAlphaL_SL,
  MFD_Gauge_VehicleSpeed,
  MFD_Gauge_EngineSpeed,
  MFD_Gauge_BoostPressure,

  MFD_Gauge__SIZE,
} MFD_GaugeType;

//MFD_Gauge_InjTime,
//MFD_Gauge_LeftMAF,
//MFD_Gauge_CansultVoltage,
//MFD_Gauge_O2Left,
//#define MFD_GAUGE_FIRST_DTC_CODE            13
//#define MFD_GAUGE_NEUTRAL_SW_STATE          14
//#define MFD_GAUGE_START_SIGNAL_STATE        15
//#define MFD_GAUGE_THROTTLE_CLOSED_STATE     16
//#define MFD_GAUGE_FUEL_PUMP_RELAY_STATE     17
//#define MFD_GAUGE_VTC_SOLENOID_STATE        18

typedef enum {
  MFD_GaugeScaleType_6_11,
  MFD_GaugeScaleType_9_17,
  MFD_GaugeScaleType_11_21,
  MFD_GaugeScaleType_SPEC_1,
} MFD_GaugeScaleType;

typedef struct
{
  int value;
  int peakValue;
  int min;
  int max;
  int redZoneFrom;
  int redZoneTo;
  float scaler;
  char name[10];
  char unitsLabel[12];
  int16_t scaleValues[11];
  MFD_GaugeScaleType scaleType;

  int8_t DEBUG_modifier;
} MFD_GaugeDataTypeDef;

typedef enum {
  MFD_Screen_Summary,
  MFD_Screen_Twin,
  MFD_Screen_Graph,
} MFD_ScreenType;

typedef enum {
  MFD_PeakCur_Peak,
  MFD_PeakCur_Current,
} MFD_PeakCurType;

typedef struct
{
  MFD_ScreenType currentScreen;
  MFD_PeakCurType peakCurState;

  MFD_GaugeType twinsGauge1;
  MFD_GaugeType twinsGauge2;

  MFD_GaugeType graphGauge;
} MFD_AppStateTypeDef;

extern MFD_AppStateTypeDef MFD_AppState;
extern MFD_GaugeDataTypeDef MFD_GaugesAll[MFD_GAUGES_SIZE];

void MFD_DataInit(void);
MFD_GaugeDataTypeDef* MFD_GetGauge(MFD_GaugeType id);

#ifdef __cplusplus
}
#endif

#endif /* INC_MFD_DATA_H_ */
