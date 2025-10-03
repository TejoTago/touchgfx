#include <gui/sliderblinkcontrol_screen/SliderBlinkControlView.hpp>
#include <touchgfx/Color.hpp>


SliderBlinkControlView::SliderBlinkControlView()
{

}

void SliderBlinkControlView::setupScreen()
{
    SliderBlinkControlViewBase::setupScreen();
}

void SliderBlinkControlView::tearDownScreen()
{
    SliderBlinkControlViewBase::tearDownScreen();
}
void SliderBlinkControlView::visibilityControl()
{
    // Set shape visibility to match toggle button state
    tj.setVisible(toggleButton1.getState());
    tj.invalidate();  // Redraw shape area
}

// HSV to RGB conversion helper
void hsvToRgb(uint16_t h, uint8_t s, uint8_t v, uint8_t& r, uint8_t& g, uint8_t& b)
{
    float hh = h / 60.0f;
    int i = int(hh) % 6;
    float ff = hh - i;
    float p = v * (255 - s) / 255.0f;
    float q = v * (255 - s * ff) / 255.0f;
    float t = v * (255 - s * (1.0f - ff)) / 255.0f;
    switch(i)
    {
        case 0: r=v; g=t; b=p; break;
        case 1: r=q; g=v; b=p; break;
        case 2: r=p; g=v; b=t; break;
        case 3: r=p; g=q; b=v; break;
        case 4: r=t; g=p; b=v; break;
        case 5: r=v; g=p; b=q; break;
    }
    r = (uint8_t)r;
    g = (uint8_t)g;
    b = (uint8_t)b;
}

void SliderBlinkControlView::colorControl(int value)
{
    uint16_t hue = static_cast<uint16_t>(value * 360 / 100); // map 0-100 to 0-360
    uint8_t r, g, b;
    hsvToRgb(hue, 255, 255, r, g, b);
    tjPainter.setColor(touchgfx::Color::getColorFromRGB(r, g, b));
    tj.invalidate();
}

void SliderBlinkControlView::blinkControl()
{
    blinking = !blinking;  // Start or stop blinking each time button pressed
    blinkCounter = 0;      // Reset counter
    if (!blinking) {
        // Ensure shape is visible when stopping blink
        tj.setVisible(true);
        tj.invalidate();
    }
}

void SliderBlinkControlView::handleTickEvent()
{
    SliderBlinkControlViewBase::handleTickEvent();

    if (blinking) {
        blinkCounter++;
        if (blinkCounter % 15 == 0) { // Adjust 15 to set blink speed (ticks)
            bool currentVis = tj.isVisible();
            tj.setVisible(!currentVis); // Toggle visibility
            tj.invalidate();
        }
    }
}

