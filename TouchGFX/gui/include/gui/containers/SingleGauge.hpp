#ifndef SINGLEGAUGE_HPP
#define SINGLEGAUGE_HPP

#include <gui_generated/containers/SingleGaugeBase.hpp>

class SingleGauge : public SingleGaugeBase
{
public:
    SingleGauge();
    virtual ~SingleGauge() {}

    virtual void initialize();

    void updateValue(int value, uint16_t duration);

    void updatePeakValue(int value, uint16_t duration);

    void getRange(int& min, int& max);

    void setRange(int min, int max, uint16_t steps = 0, uint16_t minStep = 0);

protected:
    int currentValue;
    int currentPeakValue;
    Unicode::UnicodeChar peakValueBuffer[10];
};

#endif // SINGLEGAUGE_HPP
