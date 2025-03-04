#include <gui/graphscreen_screen/GraphScreenView.hpp>

GraphScreenView::GraphScreenView()
{
  gaugeType = MFD_AppState.graphGauge;
  gaugeData = MFD_GetGauge(gaugeType);
}

void GraphScreenView::setupScreen()
{
  gauge1.setConfig(gaugeData);
  graph1.setConfig(gaugeData);

  GraphScreenViewBase::setupScreen();
}

void GraphScreenView::tearDownScreen()
{
  GraphScreenViewBase::tearDownScreen();
}

void GraphScreenView::handleTickEvent()
{
  if (gaugeType != MFD_AppState.graphGauge) {
    gaugeType = MFD_AppState.graphGauge;
    gaugeData = MFD_GetGauge(gaugeType);
    gauge1.setConfig(gaugeData);
    gauge1.update(true);

    graph1.setConfig(gaugeData);
  }

  if (peakCurState != MFD_AppState.peakCurState) {
    peakCurState = MFD_AppState.peakCurState;
    if (peakCurState == MFD_PeakCur_Current) {
      gauge1.showCurrent();
    } else {
      gauge1.showPeak();
    }
  }

  gauge1.update(false);

  tickCount++;
  if (tickCount >= 2) {
    tickCount = 0;
    graph1.addPoint(gaugeData->value);
  }
}
