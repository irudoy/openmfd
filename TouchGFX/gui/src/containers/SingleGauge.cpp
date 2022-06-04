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
    Unicode::snprintf(peakValueBuffer, 10, "%d", currentPeakValue);
    peak_value.setWildcard(peakValueBuffer);
    peak_value.invalidate();
}

void SingleGauge::getRange(int& min, int& max)
{
  gauge_value.getRange(min, max);
}

void SingleGauge::setRange(int min, int max, uint16_t steps /*= 0*/, uint16_t minStep /*= 0*/)
{
  gauge_value.setRange(min, max, steps, minStep);
  gauge_arc.setRange(min, max, steps, minStep);
  gauge_peak.setRange(min, max, steps, minStep);
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
    Unicode::snprintf(peakValueBuffer, 10, "%d", value);
    peak_value.setWildcard(peakValueBuffer);
    peak_value.invalidate();

    currentPeakValue = value;
  }
}
