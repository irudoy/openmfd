#ifndef SINGLEGAUGE_HPP
#define SINGLEGAUGE_HPP

#include <gui_generated/containers/SingleGaugeBase.hpp>

class SingleGauge : public SingleGaugeBase
{
public:
    SingleGauge();
    virtual ~SingleGauge() {}

    virtual void initialize();

    /**
     * Update the current value in the range (min..max) set by setRange(). Values lower than min
     * are mapped to min, values higher than max are mapped to max. The value is changed
     * gradually in the given number of ticks using the easing equation set in
     * setEasingEquation. Function setValue() is called for every new value during the change of
     * value, and if a callback function has been set using setValueSetAction, that callback
     * will be called for every new value. The callback set using setValueUpdatedCallback is
     * called when the animation has finished.
     *
     * @param  value    The value.
     * @param  duration The duration.
     *
     * @see setValue, setEasingEquation, setValueSetAction, setValueUpdatedAction
     *
     * @note If duration is 0, setValue will be called immediately and the valueUpdated action is
     *       called immediately.
     */
    void updateValue(int value, uint16_t duration);

    /**
     * Get current value
     */
    int getValue();

    /**
     * Gets the range from child Gauge
     *
     * @param [out] min The minimum input value.
     * @param [out] max The maximum input value.
     *
     * @see setRange
     */
    void getRange(int& min, int& max);

protected:
    int currentValue;
    int peakValue;
    Unicode::UnicodeChar peakValueBuffer[10];
};

#endif // SINGLEGAUGE_HPP
