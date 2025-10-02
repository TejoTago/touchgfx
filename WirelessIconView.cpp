#include <gui/wirelessicon_screen/WirelessIconView.hpp>
#include <gui/common/FrontendApplication.hpp>

WirelessIconView::WirelessIconView()
    : currentCircleIndex(0), tickCounter(0), blinkInterval(60), stageCounter(0), blinkingActive(false)
{
    circles[0] = &circle10;
    circles[1] = &circle20;
    circles[2] = &circle40;
    circles[3] = &circle60;
    circles[4] = &circle80;
}

void WirelessIconView::setupScreen()
{
    WirelessIconViewBase::setupScreen();

//    toggleCallback = touchgfx::Callback<WirelessIconView>(this, &WirelessIconView::onToggleChanged);
//    toggleButton1.setAction(toggleCallback);
    toggleCallback = touchgfx::Callback<WirelessIconView, const touchgfx::AbstractButton&>(this, &WirelessIconView::onToggleChanged);
    toggleButton1.setAction(toggleCallback);


    //static_cast<FrontendApplication*>(Application::getInstance())->addTickCallback(this);
    tickReceiver.setPosition(0, 0, 1, 1); // Minimal size
    add(tickReceiver);
    Application::getInstance()->registerTimerWidget(&tickReceiver);
}

void WirelessIconView::tearDownScreen()
{
    //static_cast<FrontendApplication*>(Application::getInstance())->removeTickCallback(this);
	Application::getInstance()->unregisterTimerWidget(&tickReceiver);
    WirelessIconViewBase::tearDownScreen();
}

void WirelessIconView::onToggleChanged(const touchgfx::AbstractButton& source)
{
    blinkingActive = toggleButton1.getState();

    if (blinkingActive)
    {
        stageCounter = 0;
//        blinkInterval = 60; // Start slow
        blinkInterval = 30;
        tickCounter = 0;
        currentCircleIndex = 0;
    }
    else
    {
        for (int i = 0; i < NUM_CIRCLES; ++i)
        {
            circles[i]->setVisible(false);
        }
        invalidate();
    }
}

void WirelessIconView::handleTickEvent()
{
    if (!blinkingActive)
        return;

    tickCounter++;

    // Advance stage every 5 seconds (assuming 60 ticks per second)
    if (tickCounter % (30 * 5) == 0 && stageCounter < 4)
    {
        stageCounter++;
        blinkInterval = blinkInterval > 10 ? blinkInterval - 10 : 10; // Speed up
    }

    if (tickCounter % blinkInterval == 0)
    {
        for (int i = 0; i < NUM_CIRCLES; ++i)
        {
            circles[i]->setVisible(false);
        }

        circles[currentCircleIndex]->setVisible(true);
        currentCircleIndex = (currentCircleIndex + 1) % NUM_CIRCLES;

        invalidate();
    }
}
