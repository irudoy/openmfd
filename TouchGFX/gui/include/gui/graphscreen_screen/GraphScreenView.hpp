#ifndef GRAPHSCREENVIEW_HPP
#define GRAPHSCREENVIEW_HPP

#include <gui_generated/graphscreen_screen/GraphScreenViewBase.hpp>
#include <gui/graphscreen_screen/GraphScreenPresenter.hpp>

#include "data.h"

class GraphScreenView : public GraphScreenViewBase
{
public:
    GraphScreenView();
    virtual ~GraphScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void handleTickEvent();
protected:
    MFD_PeakCurType peakCurState;
    MFD_GaugeType gaugeType;
    MFD_GaugeDataTypeDef *gaugeData;

    int tickCount;
};

#endif // GRAPHSCREENVIEW_HPP
