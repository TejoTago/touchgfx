#include <gui/radiobuttonsemaphorenew_screen/RadioButtonSemaphoreNewView.hpp>

RadioButtonSemaphoreNewView::RadioButtonSemaphoreNewView()
: currentMode(OFF), tickCounter(0), currentLightIndex(0)

{

}

void RadioButtonSemaphoreNewView::setupScreen()
{
    RadioButtonSemaphoreNewViewBase::setupScreen();
    semaphore();
}

void RadioButtonSemaphoreNewView::tearDownScreen()
{
    RadioButtonSemaphoreNewViewBase::tearDownScreen();
}

void RadioButtonSemaphoreNewView::semaphore()
{
    currentLightIndex = 0;

    if (radioButtonOFF.getSelected())
    {
        currentMode = OFF;
        greenON.setVisible(false);
        yellowON.setVisible(false);
        redON.setVisible(false);
    }
    else if (radioButtonSlow.getSelected())
    {
        currentMode = SLOW;
        tickCounter = 0;
    }
    else if (radioButtonFast.getSelected())
    {
        currentMode = FAST;
        tickCounter = 0;
    }

    invalidate();
}

void RadioButtonSemaphoreNewView::handleTickEvent()
{
    tickCounter++;

    if ((currentMode == SLOW && tickCounter % 30 == 0) ||
        (currentMode == FAST && tickCounter % 10 == 0))
    {
        updateSemaphoreLights();
    }
}

void RadioButtonSemaphoreNewView::updateSemaphoreLights()
{
    // Hide all lights first
    greenON.setVisible(false);
    yellowON.setVisible(false);
    redON.setVisible(false);

    // Show the current light
    switch (currentLightIndex)
    {
        case 0:
            greenON.setVisible(true);
            break;
        case 1:
            yellowON.setVisible(true);
            break;
        case 2:
            redON.setVisible(true);
            break;
    }

    currentLightIndex = (currentLightIndex + 1) % 3;

    invalidate();
}
