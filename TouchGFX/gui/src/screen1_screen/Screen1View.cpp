#include <gui/screen1_screen/Screen1View.hpp>

#include "main.h"

extern RNG_HandleTypeDef hrng;

Screen1View::Screen1View()
{
  modifier = 1;
  tickCounter = 0;
  useRandom = true;
}

void Screen1View::handleBtnClick()
{
  useRandom = !useRandom;
}

void Screen1View::setupScreen()
{
  Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
  Screen1ViewBase::tearDownScreen();
}

void Screen1View::handleTickEvent()
{
  tickCounter++;

  int minValue;
  int maxValue;
  gauge1.getRange(minValue, maxValue);

  int currentValue = gauge1.getValue();

  if (currentValue == minValue || currentValue == maxValue) {
    modifier *= -1;
  }

  if (tickCounter % 30 == 0 || !useRandom) {
    gauge1.updateValue(
      useRandom ? HAL_RNG_GetRandomNumber(&hrng) % 100 : gauge1.getValue() + modifier,
      useRandom ? 30 : 0
    );
    gauge2.updateValue(
      useRandom ? HAL_RNG_GetRandomNumber(&hrng) % 100 : gauge2.getValue() + modifier,
      useRandom ? 30 : 0
    );
  }
}
