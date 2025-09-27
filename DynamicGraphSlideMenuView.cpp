#include <gui/DynamicGraphSlideMenu_screen/DynamicGraphSlideMenuView.hpp>
#include <cstdlib>

DynamicGraphSlideMenuView::DynamicGraphSlideMenuView()
    : tickCounter(0), lastBlueValue(0), lastGreenValue(0), last0Value(0)
{
	srand(tickCounter);
}

void DynamicGraphSlideMenuView::setupScreen()
{
    DynamicGraphSlideMenuViewBase::setupScreen();
    toggleBlueLine.forceState(true);
    toggleBlueDots.forceState(true);
    toggleGreenLine.forceState(true);
    toggleGreenDots.forceState(true);
    toggleBox.forceState(false);
    toggleGrid.forceState(false);
    updateBlueGraph();
    updateGreenGraph();
    customizeScreen();
}

void DynamicGraphSlideMenuView::tearDownScreen()
{
    DynamicGraphSlideMenuViewBase::tearDownScreen();
}

void DynamicGraphSlideMenuView::handleTickEvent()
{
    tickCounter++;
    if (tickCounter % 10 == 0)
    {
        dynamicGraphBlue.addDataPoint(generateDeltaValue(lastBlueValue, -20, 100, 5));
        dynamicGraphGreen.addDataPoint(generateDeltaValue(lastGreenValue, -20, 100, 5));
        dynamicGraph0.addDataPoint(generateDeltaValue(last0Value, -20, 100, 5));
    }
}

int16_t DynamicGraphSlideMenuView::generateDeltaValue(int16_t& lastValue, int16_t min, int16_t max, int16_t maxDelta)
{
    int16_t delta = (rand() % (2 * maxDelta + 1)) - maxDelta; // Range: [-maxDelta, +maxDelta]
    int16_t newValue = lastValue + delta;

    // Clamp to min/max
    if (newValue < min) newValue = min;
    if (newValue > max) newValue = max;

    lastValue = newValue;
    return newValue;
}

void DynamicGraphSlideMenuView::updateLineVisibility(touchgfx::ToggleButton& toggle, touchgfx::GraphElementLine& line)
{
    line.setAlpha(toggle.getState() ? 255 : 0);
    line.invalidate();
}

void DynamicGraphSlideMenuView::updateDotsVisibility(touchgfx::ToggleButton& toggle, touchgfx::GraphElementDots& dots)
{
    dots.setAlpha(toggle.getState() ? 255 : 0);
    dots.invalidate();
}

void DynamicGraphSlideMenuView::updateGraphElements(touchgfx::ToggleButton& lineToggle,
                                               touchgfx::GraphElementLine& line,
                                               touchgfx::ToggleButton& dotsToggle,
                                               touchgfx::GraphElementDots& dots,
                                               touchgfx::GraphScroll<31>& graph)
{
	updateLineVisibility(lineToggle, line);
    updateDotsVisibility(dotsToggle, dots);
    graph.invalidate();
}

void DynamicGraphSlideMenuView::updateBlueGraph()
{
	updateGraphElements(toggleBlueLine, dynamicGraphBlueLine1,
	                    toggleBlueDots, dynamicGraphBlueDots1,
	                    dynamicGraphBlue);

    dynamicGraphBlue.invalidate();
}

void DynamicGraphSlideMenuView::updateGreenGraph()
{
	updateGraphElements(toggleGreenLine, dynamicGraphGreenLine1,
	                    toggleGreenDots, dynamicGraphGreenDots1,
	                    dynamicGraphGreen);
    dynamicGraphGreen.invalidate();
}

void DynamicGraphSlideMenuView::customizeScreen()
{
    if (toggleBox.getState() == false)
    {
        box1.setAlpha(0);
    }
    else
    {
        box1.setAlpha(255);
    }

    if (toggleGrid.getState() == false)
    {
    	dynamicGraph0MajorYAxisGrid.setAlpha(0);
    }
    else
    {
    	dynamicGraph0MajorYAxisGrid.setAlpha(255);
    }
    dynamicGraph0.invalidate();
}



