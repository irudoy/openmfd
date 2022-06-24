#include "data.h"

MFD_GaugeTypeDef MFD_GaugesAll[] = {};

void MFD_GaugesInit(void) {
  // CANSult
  MFD_GaugesAll[MFD_GAUGE_BATT_VOLTAGE] = (MFD_GaugeTypeDef) {
    .max = 255,
    .name = "BATT",
    .unitsLabel = "[ V ]",
    .scaleType = MFD_GaugeScaleType_9_17,
    .scaleValues = { 8, 9, 10, 11, 12, 13, 14, 15, 16 },
  };

  MFD_GaugesAll[MFD_GAUGE_CLT_TEMP] = (MFD_GaugeTypeDef) {
    .min = 50,
    .max = 150,
    .name = "CLT",
    .unitsLabel = "[ °C ]",
    .scaleType = MFD_GaugeScaleType_11_21,
    .scaleValues = { 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150 },
  };

  MFD_GaugesAll[MFD_GAUGE_IGN_TIMING] = (MFD_GaugeTypeDef) {
    .min = 0,
    .max = 50,
    .name = "IGN",
    .unitsLabel = "[ DEG ]",
    .scaleType = MFD_GaugeScaleType_6_11,
    .scaleValues = { 0, 10, 20, 30, 40, 50 },
  };

  MFD_GaugesAll[MFD_GAUGE_AAC_VALVE] = (MFD_GaugeTypeDef) {
    .min = 0,
    .max = 100,
    .name = "AAC",
    .unitsLabel = "[ % ]",
    .scaleType = MFD_GaugeScaleType_6_11,
    .scaleValues = { 0, 20, 40, 60, 80, 100 },
  };

  MFD_GaugesAll[MFD_GAUGE_AF_ALPHA_L] = (MFD_GaugeTypeDef) {
    .min = 0,
    .max = 100,
    .name = "AF L",
    .unitsLabel = "[ % ]",
    .scaleType = MFD_GaugeScaleType_6_11,
    .scaleValues = { 0, 20, 40, 60, 80, 100 },
  };

  MFD_GaugesAll[MFD_GAUGE_AF_ALPHA_L_SL] = (MFD_GaugeTypeDef) {
    .min = 0,
    .max = 100,
    .name = "AF L SL",
    .unitsLabel = "[ % ]",
    .scaleType = MFD_GaugeScaleType_6_11,
    .scaleValues = { 0, 20, 40, 60, 80, 100 },
  };

  MFD_GaugesAll[MFD_GAUGE_VEHICLE_SPEED] = (MFD_GaugeTypeDef) {
    .min = 0,
    .max = 200,
    .name = "SPEED",
    .unitsLabel = "[ km/h ]",
    .scaleType = MFD_GaugeScaleType_11_21,
    .scaleValues = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200 },
  };

  MFD_GaugesAll[MFD_GAUGE_ENGINE_SPEED] = (MFD_GaugeTypeDef) {
    .DEBUG_modifier = 50,

    .min = 0,
    .max = 8000,
    .name = "RPM",
    .unitsLabel = "[x1000 RPM]",
    .scaleType = MFD_GaugeScaleType_6_11,
    .scaleValues = { 0, 1, 2, 3, 4, 5, 6, 7, 8 },
  };

  MFD_GaugesAll[MFD_GAUGE_BOOST_PRESSURE] = (MFD_GaugeTypeDef) {
    .max = 50,
//    .min = 1.2,
//    .max = -0.6,
    .name = "BOOST",
    .unitsLabel = "[x100 kPa]",
    .scaleType = MFD_GaugeScaleType_SPEC_1,
    .scaleValues = { -0.5, 0, 0.5, 0.4, 0.6, 0.8, 1.2 },
  };

//  MFD_GaugesAll[MFD_GAUGE_CANSULT_VOLTAGE] = (MFD_GaugeTypeDef) {
//    .max = 255,
//    .name = "CANSULT V",
//    .scaleType = MFD_GaugeScaleType_9_17,
//    .scaleValues = { 8, 9, 10, 11, 12, 13, 14, 15, 16 },
//  };
//  MFD_GaugesAll[MFD_GAUGE_INJ_TIME] = (MFD_GaugeTypeDef) {
//    .max = 255,
//    .name = "INJ",
//    .scaleType = MFD_GaugeScaleType_6_11,
//    .scaleValues = { 0, 20, 40, 60, 80, 100 },
//  };
//  MFD_GaugesAll[MFD_GAUGE_TPS] = (MFD_GaugeTypeDef) {
//    .max = 255,
//    .name = "TPS",
//    .scaleType = MFD_GaugeScaleType_6_11,
//    .scaleValues = { 0, 20, 40, 60, 80, 100 },
//  };
//  MFD_GaugesAll[MFD_GAUGE_LEFT_MAF] = (MFD_GaugeTypeDef) {
//    .max = 255,
//    .name = "MAF L",
//  };
//  MFD_GaugesAll[MFD_GAUGE_O2_LEFT] = (MFD_GaugeTypeDef) {
//    .max = 255,
//    .name = "O2 L",
//  };
}

MFD_GaugeTypeDef* MFD_GetGauge(uint8_t id) {
  return &MFD_GaugesAll[id];
}
