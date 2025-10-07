#include <gui/slidershapesize_screen/SliderShapeSizeView.hpp>

SliderShapeSizeView::SliderShapeSizeView()
: sliderSizeCallback(this, &SliderShapeSizeView::sliderSizeCallbackHandler),

  sliderWidthCallback(this, &SliderShapeSizeView::sliderWidthCallbackHandler),
  sliderHeightCallback(this, &SliderShapeSizeView::sliderHeightCallbackHandler)

{
}


void SliderShapeSizeView::setupScreen()
{
    SliderShapeSizeViewBase::setupScreen();
    sliderSize.setNewValueCallback(sliderSizeCallback);

    sliderWidth.setNewValueCallback(sliderWidthCallback);
    sliderHeight.setNewValueCallback(sliderHeightCallback);
}

void SliderShapeSizeView::tearDownScreen()
{
    SliderShapeSizeViewBase::tearDownScreen();
}

void SliderShapeSizeView::sliderSizeCallbackHandler(const touchgfx::Slider& src, int value)
{
    // Map slider value (0–100) to scale factor (1.0–2.0)
    float scaleFactor = 1.0f + (value / 100.0f);

    // Apply scale to both width and height
    star.updateScale(scaleFactor, scaleFactor);
}

void SliderShapeSizeView::sliderWidthCallbackHandler(const touchgfx::Slider& src, int value)
{
    currentScaleX = 1.0f + (value / 100.0f); // scale from 1.0 to 2.0
    star.updateScale(currentScaleX, currentScaleY);
}

void SliderShapeSizeView::sliderHeightCallbackHandler(const touchgfx::Slider& src, int value)
{
    currentScaleY = 1.0f + (value / 100.0f); // scale from 1.0 to 2.0
    star.updateScale(currentScaleX, currentScaleY);
}


