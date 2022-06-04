#include "data.h"

MFD_DataSourceTypeDef MFD_DataSourcesAll[] = {};

void MFD_DataInit(void) {
  // CANSult
  MFD_DataSourcesAll[MFD_DATA_BATT_VOLTAGE] = (MFD_DataSourceTypeDef) {
    .max = 255,
    .name = "BATT",
  };
  MFD_DataSourcesAll[MFD_DATA_CLT_TEMP] = (MFD_DataSourceTypeDef) {
    .max = 255,
    .name = "CLT",
  };
  MFD_DataSourcesAll[MFD_DATA_IGN_TIMING] = (MFD_DataSourceTypeDef) {
    .max = 255,
    .name = "IGN",
  };
  MFD_DataSourcesAll[MFD_DATA_O2_LEFT] = (MFD_DataSourceTypeDef) {
    .max = 255,
    .name = "O2 L",
  };
  MFD_DataSourcesAll[MFD_DATA_TPS] = (MFD_DataSourceTypeDef) {
    .max = 255,
    .name = "TPS",
  };
  MFD_DataSourcesAll[MFD_DATA_AAC_VALVE] = (MFD_DataSourceTypeDef) {
    .max = 255,
    .name = "AAC",
  };
  MFD_DataSourcesAll[MFD_DATA_AF_ALPHA_L] = (MFD_DataSourceTypeDef) {
    .max = 255,
    .name = "AF L",
  };
  MFD_DataSourcesAll[MFD_DATA_AF_ALPHA_L_SL] = (MFD_DataSourceTypeDef) {
    .max = 255,
    .name = "AF L SL",
  };
  MFD_DataSourcesAll[MFD_DATA_VEHICLE_SPEED] = (MFD_DataSourceTypeDef) {
    .max = 255,
    .name = "SPEED",
  };
  MFD_DataSourcesAll[MFD_DATA_ENGINE_SPEED] = (MFD_DataSourceTypeDef) {
    .max = 11000,
    .name = "RPM",
    .DEBUG_modifier = 50
  };
  MFD_DataSourcesAll[MFD_DATA_INJ_TIME] = (MFD_DataSourceTypeDef) {
    .max = 255,
    .name = "INJ",
  };
  MFD_DataSourcesAll[MFD_DATA_LEFT_MAF] = (MFD_DataSourceTypeDef) {
    .max = 255,
    .name = "MAF L",
  };
  MFD_DataSourcesAll[MFD_DATA_CANSULT_VOLTAGE] = (MFD_DataSourceTypeDef) {
    .max = 255,
    .name = "CANSULT V",
  };
  MFD_DataSourcesAll[MFD_DATA_FIRST_DTC_CODE] = (MFD_DataSourceTypeDef) {
    .max = 255,
    .name = "DTC CODE",
  };
  MFD_DataSourcesAll[MFD_DATA_NEUTRAL_SW_STATE] = (MFD_DataSourceTypeDef) {
    .max = 1,
    .name = "NEUTRAL",
  };
  MFD_DataSourcesAll[MFD_DATA_START_SIGNAL_STATE] = (MFD_DataSourceTypeDef) {
    .max = 1,
    .name = "START",
  };
  MFD_DataSourcesAll[MFD_DATA_THROTTLE_CLOSED_STATE] = (MFD_DataSourceTypeDef) {
    .max = 1,
    .name = "THR CLOSED",
  };
  MFD_DataSourcesAll[MFD_DATA_FUEL_PUMP_RELAY_STATE] = (MFD_DataSourceTypeDef) {
    .max = 1,
    .name = "FPUMP",
  };
  MFD_DataSourcesAll[MFD_DATA_VTC_SOLENOID_STATE] = (MFD_DataSourceTypeDef) {
    .max = 1,
    .name = "VTC",
  };

  // Other
  MFD_DataSourcesAll[MFD_DATA_BOOST_PRESSURE] = (MFD_DataSourceTypeDef) {
    .max = 50,
    .name = "BOOST",
  };
}

MFD_DataSourceTypeDef* MFD_DataGetEntry(uint8_t id) {
  return &MFD_DataSourcesAll[id];
}
