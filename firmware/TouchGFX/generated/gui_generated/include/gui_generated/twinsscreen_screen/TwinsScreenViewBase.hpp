/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef TWINSSCREENVIEWBASE_HPP
#define TWINSSCREENVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/twinsscreen_screen/TwinsScreenPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <gui/containers/SingleGauge.hpp>

class TwinsScreenViewBase : public touchgfx::View<TwinsScreenPresenter>
{
public:
    TwinsScreenViewBase();
    virtual ~TwinsScreenViewBase() {}
    virtual void setupScreen();
    virtual void handleKeyEvent(uint8_t key);

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box bg;
    SingleGauge gauge2;
    SingleGauge gauge1;

private:

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 4800;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // TWINSSCREENVIEWBASE_HPP
