#include <gui/screen1_screen/Screen1View.hpp>

#include "main.h"

extern RNG_HandleTypeDef hrng;

Screen1View::Screen1View() {
  modifier = 1;
  peakValue = 0;
  tickCounter = 0;
  useRandom = true;
}

void Screen1View::handleBtnClick() {
  useRandom = !useRandom;
}

void Screen1View::setupScreen() {
  Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen() {
  Screen1ViewBase::tearDownScreen();
}

void Screen1View::handleTickEvent() {
  tickCounter++;

  int minValue;
  int maxValue;
  gauge_value.getRange(minValue, maxValue);

  int currentValue = gauge_value.getValue();

  if (currentValue == minValue || currentValue == maxValue) {
    modifier *= -1;
  }

  int transitionTime = useRandom ? 30 : 0;

  if (tickCounter % 30 == 0 || !useRandom) {
    int newValue = useRandom ? HAL_RNG_GetRandomNumber(&hrng) % 100 : gauge_value.getValue() + modifier;

    if (currentValue <= 10) peakValue = 0;
    if (newValue >= peakValue) peakValue = newValue;

    gauge_value.updateValue(newValue, transitionTime);
    gauge_arc.updateValue(newValue, transitionTime);
    gauge_peak.updateValue(peakValue, transitionTime);

    Unicode::snprintf(peakValueBuffer, 10, "%d", peakValue);
    peak_value.setWildcard(peakValueBuffer);
    peak_value.invalidate();
  }
}
