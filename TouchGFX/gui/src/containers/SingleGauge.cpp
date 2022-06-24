#include <gui/containers/SingleGauge.hpp>

SingleGauge::SingleGauge()
{
}

void SingleGauge::initialize()
{
  SingleGaugeBase::initialize();

  gauge_value.updateValue(currentValue, 0);
  gauge_arc.updateValue(currentValue, 0);
  gauge_peak.updateValue(currentPeakValue, 0);

  Unicode::snprintf(peak_valueBuffer, PEAK_VALUE_SIZE, "%d", currentPeakValue);
  peak_value.invalidate();
}

void SingleGauge::setConfig(MFD_GaugeTypeDef *config)
{
  gauge_value.setRange(config->min, config->max, 0, 0);
  gauge_value.setStartEndAngle(gauge_value.getStartAngle(), 225); // 225 for 6_11 type

  gauge_peak.setRange(config->min, config->max, 0, 0);
  gauge_peak.setStartEndAngle(gauge_peak.getStartAngle(), 225); // 225 for 6_11 type

  gauge_arc.setRange(config->min, config->max, 0, 0);
  gauge_arc.setStartEndAngle(gauge_arc.getStartAngle(), 45); // 45 for 6_11 type

  Unicode::strncpy(units_labelBuffer, config->unitsLabel, UNITS_LABEL_SIZE);

  Unicode::snprintf(value_6_11_0Buffer, VALUE_6_11_0_SIZE, "%d", config->scaleValues[0]);
  Unicode::snprintf(value_6_11_1Buffer, VALUE_6_11_1_SIZE, "%d", config->scaleValues[1]);
  Unicode::snprintf(value_6_11_2Buffer, VALUE_6_11_2_SIZE, "%d", config->scaleValues[2]);
  Unicode::snprintf(value_6_11_3Buffer, VALUE_6_11_3_SIZE, "%d", config->scaleValues[3]);
  Unicode::snprintf(value_6_11_4Buffer, VALUE_6_11_4_SIZE, "%d", config->scaleValues[4]);
  Unicode::snprintf(value_6_11_5Buffer, VALUE_6_11_5_SIZE, "%d", config->scaleValues[5]);
}

void SingleGauge::updateValue(int value, uint16_t duration)
{
  if (value != currentValue) {
    gauge_value.updateValue(value, duration);
    gauge_arc.updateValue(value, duration);

    currentValue = value;
  }
}

void SingleGauge::updatePeakValue(int value, uint16_t duration)
{
  if (value != currentPeakValue) {
    gauge_peak.updateValue(value, duration);

    Unicode::snprintf(peak_valueBuffer, PEAK_VALUE_SIZE, "%d", value);
    peak_value.invalidate();

    currentPeakValue = value;
  }
}
