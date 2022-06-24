#ifndef SINGLEGAUGE_HPP
#define SINGLEGAUGE_HPP

#include <gui_generated/containers/SingleGaugeBase.hpp>

#include "data.h"

class SingleGauge : public SingleGaugeBase
{
public:
    SingleGauge();
    virtual ~SingleGauge() {}

    virtual void initialize();

    void updateValue();

    void updatePeakValue();

    void setConfig(MFD_GaugeTypeDef *config);

protected:
    int updateDuration;
    int currentValue;
    int currentPeakValue;
    MFD_GaugeTypeDef *data;
};

#endif // SINGLEGAUGE_HPP
