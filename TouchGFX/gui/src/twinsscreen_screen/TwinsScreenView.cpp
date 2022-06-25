#include <gui/twinsscreen_screen/TwinsScreenView.hpp>

TwinsScreenView::TwinsScreenView()
{
  gaugeType1 = MFD_AppState.twinsGauge1;
  gaugeData1 = MFD_GetGauge(gaugeType1);

  gaugeType2 = MFD_AppState.twinsGauge2;
  gaugeData2 = MFD_GetGauge(gaugeType2);
}

void TwinsScreenView::setupScreen()
{
  gauge1.setConfig(gaugeData1);
  gauge2.setConfig(gaugeData2);

  TwinsScreenViewBase::setupScreen();
}

void TwinsScreenView::tearDownScreen()
{
  TwinsScreenViewBase::tearDownScreen();
}

void TwinsScreenView::handleTickEvent()
{
  if (gaugeType1 != MFD_AppState.twinsGauge1) {
    gaugeType1 = MFD_AppState.twinsGauge1;
    gaugeData1 = MFD_GetGauge(gaugeType1);
    gauge1.setConfig(gaugeData1);
    gauge1.update(true);
  }

  if (gaugeType2 != MFD_AppState.twinsGauge2) {
    gaugeType2 = MFD_AppState.twinsGauge2;
    gaugeData2 = MFD_GetGauge(gaugeType2);
    gauge2.setConfig(gaugeData2);
    gauge2.update(true);
  }

  if (peakCurState != MFD_AppState.peakCurState) {
    peakCurState = MFD_AppState.peakCurState;
    if (peakCurState == MFD_PeakCur_Current) {
      gauge1.showCurrent();
      gauge2.showCurrent();
    } else {
      gauge1.showPeak();
      gauge2.showPeak();
    }
  }

  gauge1.update(false);
  gauge2.update(false);
}
