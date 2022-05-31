#include <gui/containers/SingleGauge.hpp>

SingleGauge::SingleGauge()
{
  currentValue = 0;
  peakValue = 0;
}

void SingleGauge::initialize()
{
    SingleGaugeBase::initialize();
}

int SingleGauge::getValue()
{
  return currentValue;
}

void SingleGauge::getRange(int& min, int& max)
{
  gauge_value.getRange(min, max);
}

void SingleGauge::updateValue(int value, uint16_t duration)
{
  currentValue = value;

  if (currentValue <= 10) peakValue = 0;
  if (currentValue >= peakValue) peakValue = value;

  gauge_value.updateValue(currentValue, duration);
  gauge_arc.updateValue(currentValue, duration);
  gauge_peak.updateValue(peakValue, duration);

  Unicode::snprintf(peakValueBuffer, 10, "%d", peakValue);
  peak_value.setWildcard(peakValueBuffer);
  peak_value.invalidate();
}
