#ifndef SLIDERSHAPESIZEVIEW_HPP
#define SLIDERSHAPESIZEVIEW_HPP

#include <gui_generated/slidershapesize_screen/SliderShapeSizeViewBase.hpp>
#include <gui/slidershapesize_screen/SliderShapeSizePresenter.hpp>
#include <touchgfx/Callback.hpp>


class SliderShapeSizeView : public SliderShapeSizeViewBase
{
public:
    SliderShapeSizeView();
    virtual ~SliderShapeSizeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
        touchgfx::Callback<SliderShapeSizeView, const touchgfx::Slider&, int> sliderSizeCallback;
        void sliderSizeCallbackHandler(const touchgfx::Slider& src, int value);

    touchgfx::Callback<SliderShapeSizeView, const touchgfx::Slider&, int> sliderWidthCallback;
    touchgfx::Callback<SliderShapeSizeView, const touchgfx::Slider&, int> sliderHeightCallback;

    void sliderWidthCallbackHandler(const touchgfx::Slider& src, int value);
    void sliderHeightCallbackHandler(const touchgfx::Slider& src, int value);

    float currentScaleX = 1.0f;
    float currentScaleY = 1.0f;

};

#endif // SLIDERSHAPESIZEVIEW_HPP
