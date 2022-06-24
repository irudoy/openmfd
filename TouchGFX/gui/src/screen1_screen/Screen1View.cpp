#include <gui/screen1_screen/Screen1View.hpp>

#include "data.h"

MFD_GaugeTypeDef *boostPres = MFD_GetGauge(MFD_GAUGE_BOOST_PRESSURE);
MFD_GaugeTypeDef *engSpeed = MFD_GetGauge(MFD_GAUGE_ENGINE_SPEED);

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
  Screen1ViewBase::setupScreen();

  gauge1.setConfig(engSpeed);
  gauge2.setConfig(boostPres);
}

void Screen1View::tearDownScreen()
{
  Screen1ViewBase::tearDownScreen();
}

void Screen1View::handleTickEvent()
{
  gauge1.updateValue();
  gauge1.updatePeakValue();

  gauge2.updateValue();
  gauge2.updatePeakValue();
}
