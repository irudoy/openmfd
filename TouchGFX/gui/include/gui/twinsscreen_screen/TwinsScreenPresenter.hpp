#ifndef TWINSSCREENPRESENTER_HPP
#define TWINSSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class TwinsScreenView;

class TwinsScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    TwinsScreenPresenter(TwinsScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~TwinsScreenPresenter() {};

private:
    TwinsScreenPresenter();

    TwinsScreenView& view;
};

#endif // TWINSSCREENPRESENTER_HPP
