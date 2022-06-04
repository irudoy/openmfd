#include <gui/screen1_screen/Screen1View.hpp>

#include "data.h"

MFD_DataSourceTypeDef *boostPres = MFD_DataGetEntry(MFD_DATA_BOOST_PRESSURE);
MFD_DataSourceTypeDef *engSpeed = MFD_DataGetEntry(MFD_DATA_ENGINE_SPEED);

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
  Screen1ViewBase::setupScreen();

  gauge1.setRange(boostPres->min, boostPres->max);
  gauge2.setRange(engSpeed->min, engSpeed->max);
}

void Screen1View::tearDownScreen()
{
  Screen1ViewBase::tearDownScreen();
}

void Screen1View::handleTickEvent()
{
  gauge1.updateValue(boostPres->value, 5);
  gauge1.updatePeakValue(boostPres->peakValue, 5);

  gauge2.updateValue(engSpeed->value, 5);
  gauge2.updatePeakValue(engSpeed->peakValue, 5);
}
