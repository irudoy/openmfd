#include "data.h"

MFD_GaugeDataTypeDef MFD_GaugesAll[] = {};

MFD_AppStateTypeDef MFD_AppState = {
  .currentScreen = MFD_Screen_Summary,
  .peakCurState = MFD_PeakCur_Peak,

  .twinsGauge1 = MFD_Gauge_BattVoltage,
  .twinsGauge2 = MFD_Gauge_CltTemp,

  .graphGauge = MFD_Gauge_BoostPressure,
};

void MFD_DataInit(void) {
  MFD_GaugesAll[MFD_Gauge_BattVoltage] = (MFD_GaugeDataTypeDef) {
    .scaler = 10.0f,
    .min = 80,
    .max = 160,
    .redZoneFrom = 80,
    .redZoneTo = 110,
    .name = "BATT",
    .unitsLabel = "[ V ]",
    .scaleType = MFD_GaugeScaleType_9_17,
    .scaleValues = { 8, 9, 10, 11, 12, 13, 14, 15, 16 },
  };

  MFD_GaugesAll[MFD_Gauge_CltTemp] = (MFD_GaugeDataTypeDef) {
    .min = 50,
    .max = 150,
    .redZoneFrom = 120,
    .redZoneTo = 150,
    .name = "CLT",
    .unitsLabel = "[ °C ]",
    .scaleType = MFD_GaugeScaleType_11_21,
    .scaleValues = { 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150 },
  };

  MFD_GaugesAll[MFD_Gauge_IgnTiming] = (MFD_GaugeDataTypeDef) {
    .min = 0,
    .max = 50,
    .name = "IGN",
    .unitsLabel = "[ DEG ]",
    .scaleType = MFD_GaugeScaleType_6_11,
    .scaleValues = { 0, 10, 20, 30, 40, 50 },
  };

  MFD_GaugesAll[MFD_Gauge_AACValve] = (MFD_GaugeDataTypeDef) {
    .min = 0,
    .max = 100,
    .name = "AAC",
    .unitsLabel = "[ % ]",
    .scaleType = MFD_GaugeScaleType_6_11,
    .scaleValues = { 0, 20, 40, 60, 80, 100 },
  };

  MFD_GaugesAll[MFD_Gauge_AFAlphaL] = (MFD_GaugeDataTypeDef) {
    .min = 0,
    .max = 100,
    .name = "AF L",
    .unitsLabel = "[ % ]",
    .scaleType = MFD_GaugeScaleType_6_11,
    .scaleValues = { 0, 20, 40, 60, 80, 100 },
  };

  MFD_GaugesAll[MFD_Gauge_AFAlphaL_SL] = (MFD_GaugeDataTypeDef) {
    .min = 0,
    .max = 100,
    .name = "AF L SL",
    .unitsLabel = "[ % ]",
    .scaleType = MFD_GaugeScaleType_6_11,
    .scaleValues = { 0, 20, 40, 60, 80, 100 },
  };

  MFD_GaugesAll[MFD_Gauge_VehicleSpeed] = (MFD_GaugeDataTypeDef) {
    .min = 0,
    .max = 200,
    .name = "SPEED",
    .unitsLabel = "[ km/h ]",
    .scaleType = MFD_GaugeScaleType_11_21,
    .scaleValues = { 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200 },
  };

  MFD_GaugesAll[MFD_Gauge_EngineSpeed] = (MFD_GaugeDataTypeDef) {
    .DEBUG_modifier = 50,

    .min = 0,
    .max = 8000,
    .redZoneFrom = 6500,
    .redZoneTo = 8000,
    .name = "RPM",
    .unitsLabel = "[x1000 RPM]",
    .scaleType = MFD_GaugeScaleType_9_17,
    .scaleValues = { 0, 1, 2, 3, 4, 5, 6, 7, 8 },
  };

  MFD_GaugesAll[MFD_Gauge_BoostPressure] = (MFD_GaugeDataTypeDef) {
    .scaler = 10.0f,
    .min = -6,
    .max = 12,
    .redZoneFrom = 9,
    .redZoneTo = 12,
    .name = "BOOST",
    .unitsLabel = "[x100 kPa]",
    .scaleType = MFD_GaugeScaleType_SPEC_1,
    .scaleValues = { -5, 0, 2, 4, 6, 8, 10, 12 },
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

MFD_GaugeDataTypeDef* MFD_GetGauge(MFD_GaugeType id) {
  return &MFD_GaugesAll[id];
}
