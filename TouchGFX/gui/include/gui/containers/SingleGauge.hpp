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

    void updateValue(int value, uint16_t duration);

    void updatePeakValue(int value, uint16_t duration);

    void setConfig(MFD_GaugeTypeDef *config);

protected:
    int currentValue;
    int currentPeakValue;
};

#endif // SINGLEGAUGE_HPP
