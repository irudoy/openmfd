#include "data.h"

MFD_GaugeTypeDef MFD_GaugesAll[] = {};

void MFD_GaugesInit(void) {
  // CANSult
  MFD_GaugesAll[MFD_GAUGE_BATT_VOLTAGE] = (MFD_GaugeTypeDef) {
    .max = 255,
    .name = "BATT",
  };
  MFD_GaugesAll[MFD_GAUGE_CLT_TEMP] = (MFD_GaugeTypeDef) {
    .min = 50,
    .max = 150,
    .name = "CLT",
  };
  MFD_GaugesAll[MFD_GAUGE_IGN_TIMING] = (MFD_GaugeTypeDef) {
    .max = 255,
    .name = "IGN",
  };
  MFD_GaugesAll[MFD_GAUGE_O2_LEFT] = (MFD_GaugeTypeDef) {
    .max = 255,
    .name = "O2 L",
  };
  MFD_GaugesAll[MFD_GAUGE_TPS] = (MFD_GaugeTypeDef) {
    .max = 255,
    .name = "TPS",
  };
  MFD_GaugesAll[MFD_GAUGE_AAC_VALVE] = (MFD_GaugeTypeDef) {
    .max = 255,
    .name = "AAC",
  };
  MFD_GaugesAll[MFD_GAUGE_AF_ALPHA_L] = (MFD_GaugeTypeDef) {
    .max = 255,
    .name = "AF L",
  };
  MFD_GaugesAll[MFD_GAUGE_AF_ALPHA_L_SL] = (MFD_GaugeTypeDef) {
    .max = 255,
    .name = "AF L SL",
  };
  MFD_GaugesAll[MFD_GAUGE_VEHICLE_SPEED] = (MFD_GaugeTypeDef) {
    .max = 255,
    .name = "SPEED",
  };
  MFD_GaugesAll[MFD_GAUGE_ENGINE_SPEED] = (MFD_GaugeTypeDef) {
    .max = 11000,
    .name = "RPM",
    .unitsLabel = "[x1000 RPM]",
    .DEBUG_modifier = 50,
    .scaleValues = { 0, 1, 2, 3, 4, 5, 6, 7, 8 },
  };
  MFD_GaugesAll[MFD_GAUGE_INJ_TIME] = (MFD_GaugeTypeDef) {
    .max = 255,
    .name = "INJ",
  };
  MFD_GaugesAll[MFD_GAUGE_LEFT_MAF] = (MFD_GaugeTypeDef) {
    .max = 255,
    .name = "MAF L",
  };
  MFD_GaugesAll[MFD_GAUGE_CANSULT_VOLTAGE] = (MFD_GaugeTypeDef) {
    .max = 255,
    .name = "CANSULT V",
  };

  // Other
  MFD_GaugesAll[MFD_GAUGE_BOOST_PRESSURE] = (MFD_GaugeTypeDef) {
    .max = 50,
    .name = "BOOST",
    .unitsLabel = "[x100 kPa]",
    .scaleValues = { 0, 20, 40, 60, 80, 100 },
  };
}

MFD_GaugeTypeDef* MFD_GetGauge(uint8_t id) {
  return &MFD_GaugesAll[id];
}
