/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDAPPLICATIONBASE_HPP
#define FRONTENDAPPLICATIONBASE_HPP

#include <mvp/MVPApplication.hpp>
#include <gui/model/Model.hpp>

class FrontendHeap;

class FrontendApplicationBase : public touchgfx::MVPApplication
{
public:
    FrontendApplicationBase(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplicationBase() { }

    virtual void changeToStartScreen()
    {
        gotoGraphScreenScreenNoTransition();
    }

    // TwinsScreen
    void gotoTwinsScreenScreenNoTransition();

    // GraphScreen
    void gotoGraphScreenScreenNoTransition();

    // Test
    void gotoTestScreenNoTransition();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // TwinsScreen
    void gotoTwinsScreenScreenNoTransitionImpl();

    // GraphScreen
    void gotoGraphScreenScreenNoTransitionImpl();

    // Test
    void gotoTestScreenNoTransitionImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP