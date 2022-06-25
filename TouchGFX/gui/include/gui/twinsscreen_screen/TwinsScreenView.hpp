#ifndef TWINSSCREENVIEW_HPP
#define TWINSSCREENVIEW_HPP

#include <gui_generated/twinsscreen_screen/TwinsScreenViewBase.hpp>
#include <gui/twinsscreen_screen/TwinsScreenPresenter.hpp>

#include "data.h"

class TwinsScreenView : public TwinsScreenViewBase
{
public:
    TwinsScreenView();
    virtual ~TwinsScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void handleTickEvent();
protected:
    MFD_PeakCurType peakCurState;
    MFD_GaugeType gaugeType1;
    MFD_GaugeType gaugeType2;
    MFD_GaugeDataTypeDef *gaugeData1;
    MFD_GaugeDataTypeDef *gaugeData2;
};

#endif // TWINSSCREENVIEW_HPP
