#ifndef SINGLEGAUGE_HPP
#define SINGLEGAUGE_HPP

#include <gui_generated/containers/SingleGaugeBase.hpp>

#include <data.h>

class SingleGauge : public SingleGaugeBase
{
public:
    SingleGauge();
    virtual ~SingleGauge() {}

    virtual void initialize();

    void update(bool instant);

    void setConfig(MFD_GaugeDataTypeDef *config);

    void showPeak();
    void showCurrent();

    static bool inRedZone(MFD_GaugeDataTypeDef *gauge);

protected:
    bool shouldShowPeak;
    int updateDuration;
    int currentValue;
    int currentPeakValue;
    MFD_GaugeDataTypeDef *data;
};

#endif // SINGLEGAUGE_HPP
