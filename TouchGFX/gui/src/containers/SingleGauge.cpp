#include <gui/containers/SingleGauge.hpp>

static const uint16_t MFD_GAUGE_FULL_6_11 = 225;
static const uint16_t MFD_GAUGE_FULL_9_17 = 240;
static const uint16_t MFD_GAUGE_FULL_11_21 = 270;

SingleGauge::SingleGauge()
{
}

void SingleGauge::initialize()
{
  SingleGaugeBase::initialize();

  updateDuration = 5;
  shouldShowPeak = true;
}

void SingleGauge::showPeak()
{
  peak_caption.setVisible(true);
  peak_caption.invalidate();
  peak_value.setVisible(true);
  peak_value.invalidate();
  current_value.setVisible(false);
  current_value.invalidate();
  shouldShowPeak = true;
}

void SingleGauge::showCurrent()
{
  peak_caption.setVisible(false);
  peak_caption.invalidate();
  peak_value.setVisible(false);
  peak_value.invalidate();
  current_value.setVisible(true);
  current_value.invalidate();
  shouldShowPeak = false;
}

void SingleGauge::setConfig(MFD_GaugeDataTypeDef *conf)
{
  data = conf;

  gauge_value.updateValue(currentValue, 0);

  gauge_arc.updateValue(currentValue, 0);
  gauge_arc_red.updateValue(currentValue, 0);

  gauge_peak.updateValue(currentPeakValue, 0);
  gauge_redzone.updateValue(0, 0);

  Unicode::snprintf(peak_valueBuffer, PEAK_VALUE_SIZE, "%d", currentPeakValue);
  peak_value.invalidate();

  gauge_value.setRange(data->min, data->max, 0, 0);
  gauge_peak.setRange(data->min, data->max, 0, 0);

  gauge_arc.setRange(data->min, data->max, 0, 0);
  gauge_arc_red.setRange(data->min, data->max, 0, 0);

  Unicode::strncpy(units_labelBuffer, data->unitsLabel, UNITS_LABEL_SIZE);

  // remove when icons done
  Unicode::strncpy(nameBuffer, data->name, NAME_SIZE);

  // reset all
  gauge_bg_spec_1.setVisible(false);
  gauge_bg_default.setVisible(false);

  scale_6_11.setVisible(false);
  scale_9_17.setVisible(false);
  scale_11_21.setVisible(false);
  scale_spec_1.setVisible(false);

  values_6_11.setVisible(false);
  values_9_17.setVisible(false);
  values_11_21.setVisible(false);
  values_spec_1.setVisible(false);

  uint16_t gaugeFullDeg = 0;

  switch (data->scaleType) {
    case MFD_GaugeScaleType_6_11: {
      gaugeFullDeg = MFD_GAUGE_FULL_6_11;

      gauge_bg_default.setVisible(true);
      scale_6_11.setVisible(true);
      values_6_11.setVisible(true);

      Unicode::snprintf(value_6_11_0Buffer, VALUE_6_11_0_SIZE, "%d", data->scaleValues[0]);
      Unicode::snprintf(value_6_11_1Buffer, VALUE_6_11_1_SIZE, "%d", data->scaleValues[1]);
      Unicode::snprintf(value_6_11_2Buffer, VALUE_6_11_2_SIZE, "%d", data->scaleValues[2]);
      Unicode::snprintf(value_6_11_3Buffer, VALUE_6_11_3_SIZE, "%d", data->scaleValues[3]);
      Unicode::snprintf(value_6_11_4Buffer, VALUE_6_11_4_SIZE, "%d", data->scaleValues[4]);
      Unicode::snprintf(value_6_11_5Buffer, VALUE_6_11_5_SIZE, "%d", data->scaleValues[5]);

      break;
    }
    case MFD_GaugeScaleType_9_17: {
      gaugeFullDeg = MFD_GAUGE_FULL_9_17;

      gauge_bg_default.setVisible(true);
      scale_9_17.setVisible(true);
      values_9_17.setVisible(true);

      Unicode::snprintf(value_9_17_0Buffer, VALUE_9_17_0_SIZE, "%d", data->scaleValues[0]);
      Unicode::snprintf(value_9_17_1Buffer, VALUE_9_17_1_SIZE, "%d", data->scaleValues[1]);
      Unicode::snprintf(value_9_17_2Buffer, VALUE_9_17_2_SIZE, "%d", data->scaleValues[2]);
      Unicode::snprintf(value_9_17_3Buffer, VALUE_9_17_3_SIZE, "%d", data->scaleValues[3]);
      Unicode::snprintf(value_9_17_4Buffer, VALUE_9_17_4_SIZE, "%d", data->scaleValues[4]);
      Unicode::snprintf(value_9_17_5Buffer, VALUE_9_17_5_SIZE, "%d", data->scaleValues[5]);
      Unicode::snprintf(value_9_17_6Buffer, VALUE_9_17_6_SIZE, "%d", data->scaleValues[6]);
      Unicode::snprintf(value_9_17_7Buffer, VALUE_9_17_7_SIZE, "%d", data->scaleValues[7]);
      Unicode::snprintf(value_9_17_8Buffer, VALUE_9_17_8_SIZE, "%d", data->scaleValues[8]);

      break;
    }
    case MFD_GaugeScaleType_11_21: {
      gaugeFullDeg = MFD_GAUGE_FULL_11_21;

      gauge_bg_default.setVisible(true);
      scale_11_21.setVisible(true);
      values_11_21.setVisible(true);

      Unicode::snprintf(value_11_21_0Buffer, VALUE_11_21_0_SIZE, "%d", data->scaleValues[0]);
      Unicode::snprintf(value_11_21_1Buffer, VALUE_11_21_1_SIZE, "%d", data->scaleValues[1]);
      Unicode::snprintf(value_11_21_2Buffer, VALUE_11_21_2_SIZE, "%d", data->scaleValues[2]);
      Unicode::snprintf(value_11_21_3Buffer, VALUE_11_21_3_SIZE, "%d", data->scaleValues[3]);
      Unicode::snprintf(value_11_21_4Buffer, VALUE_11_21_4_SIZE, "%d", data->scaleValues[4]);
      Unicode::snprintf(value_11_21_5Buffer, VALUE_11_21_5_SIZE, "%d", data->scaleValues[5]);
      Unicode::snprintf(value_11_21_6Buffer, VALUE_11_21_6_SIZE, "%d", data->scaleValues[6]);
      Unicode::snprintf(value_11_21_7Buffer, VALUE_11_21_7_SIZE, "%d", data->scaleValues[7]);
      Unicode::snprintf(value_11_21_8Buffer, VALUE_11_21_8_SIZE, "%d", data->scaleValues[8]);
      Unicode::snprintf(value_11_21_9Buffer, VALUE_11_21_9_SIZE, "%d", data->scaleValues[9]);
      Unicode::snprintf(value_11_21_10Buffer, VALUE_11_21_10_SIZE, "%d", data->scaleValues[10]);

      break;
    }
    case MFD_GaugeScaleType_SPEC_1: {
      gaugeFullDeg = MFD_GAUGE_FULL_11_21;

      gauge_bg_spec_1.setVisible(true);
      scale_spec_1.setVisible(true);
      values_spec_1.setVisible(true);

      Unicode::snprintfFloat(value_spec_0Buffer, VALUE_SPEC_0_SIZE, "%2.1f", data->scaleValues[0] / data->scaler);

      Unicode::snprintf(value_spec_1Buffer, VALUE_SPEC_1_SIZE, "%d", data->scaleValues[1]);

      Unicode::snprintfFloat(value_spec_2Buffer, VALUE_SPEC_2_SIZE, "%2.1f", data->scaleValues[2] / data->scaler);
      Unicode::snprintfFloat(value_spec_3Buffer, VALUE_SPEC_3_SIZE, "%2.1f", data->scaleValues[3] / data->scaler);
      Unicode::snprintfFloat(value_spec_4Buffer, VALUE_SPEC_4_SIZE, "%2.1f", data->scaleValues[4] / data->scaler);
      Unicode::snprintfFloat(value_spec_5Buffer, VALUE_SPEC_5_SIZE, "%2.1f", data->scaleValues[5] / data->scaler);
      Unicode::snprintfFloat(value_spec_6Buffer, VALUE_SPEC_6_SIZE, "%2.1f", data->scaleValues[6] / data->scaler);
      Unicode::snprintfFloat(value_spec_7Buffer, VALUE_SPEC_7_SIZE, "%2.1f", data->scaleValues[7] / data->scaler);

      break;
    }
    default:
      break;
  }

  gauge_value.setStartEndAngle(gauge_value.getStartAngle(), gaugeFullDeg);
  gauge_peak.setStartEndAngle(gauge_peak.getStartAngle(), gaugeFullDeg);

  gauge_arc.setStartEndAngle(gauge_arc.getStartAngle(), gauge_arc.getStartAngle() + gaugeFullDeg);
  gauge_arc_red.setStartEndAngle(gauge_arc_red.getStartAngle(), gauge_arc.getStartAngle() + gaugeFullDeg);

  if (data->redZoneFrom != 0 || data->redZoneTo != 0) {
    float deg = (data->max - data->min) / (float)gaugeFullDeg;
    gauge_redzone.setStartEndAngle((data->redZoneFrom - data->min) / deg - 180, (data->redZoneTo - data->min) / deg - 180);
    gauge_redzone.updateValue(100, 0);
  }

  invalidate();
}

bool SingleGauge::inRedZone(MFD_GaugeDataTypeDef *gauge)
{
  if (gauge->redZoneFrom != 0 || gauge->redZoneTo != 0) {
    return gauge->value >= gauge->redZoneFrom && gauge->value <= gauge->redZoneTo;
  }
  return false;
}

void SingleGauge::update(bool instant)
{
  if (data->value != currentValue) {
    gauge_value.updateValue(data->value, instant ? updateDuration : 0);

    gauge_arc.updateValue(data->value, instant ? updateDuration : 0);
    gauge_arc_red.updateValue(data->value, instant ? updateDuration : 0);

    if (inRedZone(data)) {
      gauge_arc.setVisible(false);
      gauge_arc_red.setVisible(true);
    } else {
      gauge_arc.setVisible(true);
      gauge_arc_red.setVisible(false);
    }

    gauge_arc.invalidate();
    gauge_arc_red.invalidate();

    if (!shouldShowPeak) {
      if (data->scaler > 0) {
        Unicode::snprintfFloat(current_valueBuffer, CURRENT_VALUE_SIZE, "%2.2f", data->value / data->scaler);
      } else {
        Unicode::snprintf(current_valueBuffer, CURRENT_VALUE_SIZE, "%d", data->value);
      }
      current_value.invalidate();
    }

    currentValue = data->value;
  }

  if (data->peakValue != currentPeakValue) {
    gauge_peak.updateValue(data->peakValue, instant ? updateDuration : 0);

    if (shouldShowPeak) {
      if (data->scaler > 0) {
        Unicode::snprintfFloat(peak_valueBuffer, PEAK_VALUE_SIZE, "%2.2f", data->peakValue / data->scaler);
      } else {
        Unicode::snprintf(peak_valueBuffer, PEAK_VALUE_SIZE, "%d", data->peakValue);
      }
      peak_value.invalidate();
    }

    currentPeakValue = data->peakValue;
  }
}
